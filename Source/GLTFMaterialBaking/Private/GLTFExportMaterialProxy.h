// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "MaterialShared.h"
#include "MaterialCompiler.h"
#include "Materials/MaterialParameterCollection.h"

#include "Engine/TextureLODSettings.h"
#include "Engine/Texture2D.h"
#include "Engine/Texture.h"
#include "Engine/TextureCube.h"
#include "Engine/Texture2DArray.h"

#include "DeviceProfiles/DeviceProfileManager.h"
#include "DeviceProfiles/DeviceProfile.h"
#include "Materials/MaterialInterface.h"
#include "SceneTypes.h"
#include "Materials/Material.h"
#include "Materials/MaterialExpressionCustomOutput.h"

#include "Materials/HLSLMaterialTranslator.h"

struct FGLTFExportMaterialCompiler : public FProxyMaterialCompiler
{
	FGLTFExportMaterialCompiler(FMaterialCompiler* InCompiler) :
		FProxyMaterialCompiler(InCompiler)
	{}

	// gets value stored by SetMaterialProperty()
	virtual EShaderFrequency GetCurrentShaderFrequency() const override
	{
		return SF_Pixel;
	}

	virtual FMaterialShadingModelField GetMaterialShadingModels() const override
	{
		return MSM_MAX;
	}

	virtual int32 WorldPosition(EWorldPositionIncludedOffsets WorldPositionIncludedOffsets) override
	{
#if WITH_EDITOR
		return Compiler->MaterialBakingWorldPosition();
#else
		return Compiler->WorldPosition(WorldPositionIncludedOffsets);
#endif
	}

	virtual int32 DistanceCullFade() override
	{
		return Compiler->Constant(1.0f);
	}

	virtual int32 ParticleRelativeTime() override
	{
		return Compiler->Constant(0.0f);
	}

	virtual int32 ParticleMotionBlurFade() override
	{
		return Compiler->Constant(1.0f);
	}

	virtual int32 PixelNormalWS() override
	{
		// Current returning vertex normal since pixel normal will contain incorrect data (normal calculated from uv data used as vertex positions to render out the material)
		return Compiler->VertexNormal();
	}

	virtual int32 ParticleRandom() override
	{
		return Compiler->Constant(0.0f);
	}

	virtual int32 ParticleDirection() override
	{
		return Compiler->Constant3(0.0f, 0.0f, 0.0f);
	}

	virtual int32 ParticleSpeed() override
	{
		return Compiler->Constant(0.0f);
	}

	virtual int32 ParticleSize() override
	{
		return Compiler->Constant2(0.0f, 0.0f);
	}

	virtual int32 CameraVector() override
	{
		// NOTE: by using VertexNormal instead of a fixed (world-space) vector, we allow
		// more correct baking of materials that use the dot-product between the vertex normal
		// and the camera vector for effects such as fresnel.
		return Compiler->VertexNormal();
	}

	virtual int32 ReflectionAboutCustomWorldNormal(int32 CustomWorldNormal, int32 bNormalizeCustomWorldNormal) override
	{
		if (CustomWorldNormal == INDEX_NONE)
		{
			return INDEX_NONE;
		}

		int32 N = CustomWorldNormal;
		int32 C = CameraVector();

		if (bNormalizeCustomWorldNormal)
		{
			// N = N / sqrt(dot(N, N))
			N = Compiler->Div(N, Compiler->SquareRoot(Compiler->Dot(N, N)));
		}

		// return 2 * dot(N, C) * N - C
		return Compiler->Sub(Compiler->Mul(Compiler->Constant(2.0f), Compiler->Mul(Compiler->Dot(N, C), N)), C);
	}

#if (ENGINE_MAJOR_VERSION > 4 || ENGINE_MINOR_VERSION >= 26)
	virtual int32 PreSkinVertexOffset() override
	{
		return Compiler->PreSkinVertexOffset();
	}

	virtual int32 PostSkinVertexOffset() override
	{
		return Compiler->PostSkinVertexOffset();
	}
#endif

	virtual int32 PreSkinnedPosition() override
	{
		return Compiler->PreSkinnedPosition();
	}

	virtual int32 PreSkinnedNormal() override
	{
		return Compiler->PreSkinnedNormal();
	}

	virtual int32 VertexInterpolator(uint32 InterpolatorIndex) override
	{
		return Compiler->VertexInterpolator(InterpolatorIndex);
	}

	virtual int32 ReflectionVector() override
	{
		// Because camera vector is identical to normal vector we can work out that reflection vector will also be the same
		return Compiler->VertexNormal();
	}

#if WITH_EDITOR
	virtual int32 MaterialBakingWorldPosition() override
	{
		return Compiler->MaterialBakingWorldPosition();
	}
#endif

	virtual int32 AccessCollectionParameter(UMaterialParameterCollection* ParameterCollection, int32 ParameterIndex, int32 ComponentIndex) override
	{
		if (!ParameterCollection || ParameterIndex == -1)
		{
			return INDEX_NONE;
		}

		// Collect names of all parameters
		TArray<FName> ParameterNames;
		ParameterCollection->GetParameterNames(ParameterNames, /*bVectorParameters=*/ false);
		int32 NumScalarParameters = ParameterNames.Num();
		ParameterCollection->GetParameterNames(ParameterNames, /*bVectorParameters=*/ true);

		// Find a parameter corresponding to ParameterIndex/ComponentIndex pair
		int32 Index;
		for (Index = 0; Index < ParameterNames.Num(); Index++)
		{
			FGuid ParameterId = ParameterCollection->GetParameterId(ParameterNames[Index]);
			int32 CheckParameterIndex, CheckComponentIndex;
			ParameterCollection->GetParameterIndex(ParameterId, CheckParameterIndex, CheckComponentIndex);
			if (CheckParameterIndex == ParameterIndex && CheckComponentIndex == ComponentIndex)
			{
				// Found
				break;
			}
		}
		if (Index >= ParameterNames.Num())
		{
			// Not found, should not happen
			return INDEX_NONE;
		}

		// Create code for parameter
		if (Index < NumScalarParameters)
		{
			const FCollectionScalarParameter* ScalarParameter = ParameterCollection->GetScalarParameterByName(ParameterNames[Index]);
			check(ScalarParameter);
			return Constant(ScalarParameter->DefaultValue);
		}
		else
		{
			const FCollectionVectorParameter* VectorParameter = ParameterCollection->GetVectorParameterByName(ParameterNames[Index]);
			check(VectorParameter);
			const FLinearColor& Color = VectorParameter->DefaultValue;
			return Constant4(Color.R, Color.G, Color.B, Color.A);
		}
	}

	virtual EMaterialCompilerType GetCompilerType() const override { return EMaterialCompilerType::MaterialProxy; }
};

class FGLTFExportMaterialProxy : public FMaterial, public FMaterialRenderProxy
{
public:
	FGLTFExportMaterialProxy(UMaterialInterface* InMaterialInterface, EMaterialProperty InPropertyToCompile, const FString& InCustomOutputToCompile = TEXT(""), bool bInSynchronousCompilation = true, EBlendMode ProxyBlendMode = BLEND_Opaque, bool bTangentSpaceNormal = false)
		: FMaterial()
		, MaterialInterface(InMaterialInterface)
		, PropertyToCompile(InPropertyToCompile)
		, CustomOutputToCompile(InCustomOutputToCompile)
		, bSynchronousCompilation(bInSynchronousCompilation)
		, ProxyBlendMode(ProxyBlendMode)
		, bTangentSpaceNormal(bTangentSpaceNormal)
	{

#if (ENGINE_MAJOR_VERSION > 4 || ENGINE_MINOR_VERSION >= 26)
		SetQualityLevelProperties(GMaxRHIFeatureLevel);
#else
		SetQualityLevelProperties(EMaterialQualityLevel::High, false, GMaxRHIFeatureLevel);
#endif
		Material = InMaterialInterface->GetMaterial();
		ReferencedTextures = InMaterialInterface->GetReferencedTextures();

		const FMaterialResource* Resource = InMaterialInterface->GetMaterialResource(GMaxRHIFeatureLevel);

		FMaterialShaderMapId ResourceId;
		Resource->GetShaderMapId(GMaxRHIShaderPlatform, nullptr, ResourceId);

		// Our Id must be the same as BaseMaterialId for the shader compiler
		// to be able to set back GameThreadShaderMap after async compilation.
		Id = ResourceId.BaseMaterialId;


		{
			TArray<FShaderType*> ShaderTypes;
			TArray<FVertexFactoryType*> VFTypes;
			TArray<const FShaderPipelineType*> ShaderPipelineTypes;

#if (ENGINE_MAJOR_VERSION > 4 || ENGINE_MINOR_VERSION >= 27)
			GetDependentShaderAndVFTypes(GMaxRHIShaderPlatform, ResourceId.LayoutParams, ShaderTypes, ShaderPipelineTypes, VFTypes);
#else
			GetDependentShaderAndVFTypes(GMaxRHIShaderPlatform, ShaderTypes, ShaderPipelineTypes, VFTypes);
#endif

			// Overwrite the shader map Id's dependencies with ones that came from the FMaterial actually being compiled (this)
			// This is necessary as we change FMaterial attributes like GetShadingModels(), which factor into the ShouldCache functions that determine dependent shader types
			ResourceId.SetShaderDependencies(ShaderTypes, ShaderPipelineTypes, VFTypes, GMaxRHIShaderPlatform);
		}

		// Override with a special usage so we won't re-use the shader map used by the material for rendering
		switch (InPropertyToCompile)
		{
		case MP_BaseColor: ResourceId.Usage = EMaterialShaderMapUsage::MaterialExportBaseColor; break;
		case MP_Specular: ResourceId.Usage = EMaterialShaderMapUsage::MaterialExportSpecular; break;
		case MP_Normal: ResourceId.Usage = EMaterialShaderMapUsage::MaterialExportNormal; break;
		case MP_Tangent: ResourceId.Usage = EMaterialShaderMapUsage::MaterialExportTangent; break;
		case MP_Metallic: ResourceId.Usage = EMaterialShaderMapUsage::MaterialExportMetallic; break;
		case MP_Roughness: ResourceId.Usage = EMaterialShaderMapUsage::MaterialExportRoughness; break;
		case MP_Anisotropy: ResourceId.Usage = EMaterialShaderMapUsage::MaterialExportAnisotropy; break;
		case MP_AmbientOcclusion: ResourceId.Usage = EMaterialShaderMapUsage::MaterialExportAO; break;
		case MP_EmissiveColor: ResourceId.Usage = EMaterialShaderMapUsage::MaterialExportEmissive; break;
		case MP_Opacity: ResourceId.Usage = EMaterialShaderMapUsage::MaterialExportOpacity; break;
		case MP_OpacityMask: ResourceId.Usage = EMaterialShaderMapUsage::MaterialExportOpacityMask; break;
		case MP_SubsurfaceColor: ResourceId.Usage = EMaterialShaderMapUsage::MaterialExportSubSurfaceColor; break;

#if (ENGINE_MAJOR_VERSION > 4 || ENGINE_MINOR_VERSION >= 27)
		case MP_CustomData0: ResourceId.Usage = EMaterialShaderMapUsage::MaterialExportClearCoat; break;
		case MP_CustomData1: ResourceId.Usage = EMaterialShaderMapUsage::MaterialExportClearCoatRoughness; break;
		case MP_CustomOutput:
			ResourceId.Usage = EMaterialShaderMapUsage::MaterialExportCustomOutput;
			ResourceId.UsageCustomOutput = InCustomOutputToCompile;
			break;
		case MP_Refraction: ResourceId.Usage = static_cast<EMaterialShaderMapUsage::Type>(EMaterialShaderMapUsage::MaterialExportCustomOutput + 1); break;
		case MP_ShadingModel: ResourceId.Usage = static_cast<EMaterialShaderMapUsage::Type>(EMaterialShaderMapUsage::MaterialExportCustomOutput + 2); break;
#else
		// NOTE: the following cases for custom data 0/1 and custom output are hacks since a proper solution requires engine changes:
		case MP_CustomData0: ResourceId.Usage = static_cast<EMaterialShaderMapUsage::Type>(EMaterialShaderMapUsage::DebugViewMode + 1); break;
		case MP_CustomData1: ResourceId.Usage = static_cast<EMaterialShaderMapUsage::Type>(EMaterialShaderMapUsage::DebugViewMode + 2); break;
		case MP_CustomOutput: ResourceId.Usage = static_cast<EMaterialShaderMapUsage::Type>(EMaterialShaderMapUsage::DebugViewMode + 3); break;
		case MP_Refraction: ResourceId.Usage = static_cast<EMaterialShaderMapUsage::Type>(EMaterialShaderMapUsage::DebugViewMode + 4); break;
		case MP_ShadingModel: ResourceId.Usage = static_cast<EMaterialShaderMapUsage::Type>(EMaterialShaderMapUsage::DebugViewMode + 5); break;
#endif

		default:
			ensureMsgf(false, TEXT("ExportMaterial has no usage for property %i.  Will likely reuse the normal rendering shader and crash later with a parameter mismatch"), (int32)InPropertyToCompile);
			break;
		};

		CacheShaders(ResourceId, GMaxRHIShaderPlatform);
	}

	/** This override is required otherwise the shaders aren't ready for use when the surface is rendered resulting in a blank image */
	virtual bool RequiresSynchronousCompilation() const override { return bSynchronousCompilation; };

	/**
	* Should the shader for this material with the given platform, shader type and vertex
	* factory type combination be compiled
	*
	* @param Platform		The platform currently being compiled for
	* @param ShaderType	Which shader is being compiled
	* @param VertexFactory	Which vertex factory is being compiled (can be NULL)
	*
	* @return true if the shader should be compiled
	*/
	virtual bool ShouldCache(EShaderPlatform Platform, const FShaderType* ShaderType, const FVertexFactoryType* VertexFactoryType) const override
	{
		const bool bCorrectVertexFactory = VertexFactoryType == FindVertexFactoryType(FName(TEXT("FLocalVertexFactory"), FNAME_Find));
		const bool bPCPlatform = !IsConsolePlatform(Platform);
		const bool bCorrectFrequency = ShaderType->GetFrequency() == SF_Vertex || ShaderType->GetFrequency() == SF_Pixel;
		return bCorrectVertexFactory && bPCPlatform && bCorrectFrequency;
	}

	virtual TArrayView<UObject* const> GetReferencedTextures() const override
	{
		return ReferencedTextures;
	}

	virtual void GetStaticParameterSet(EShaderPlatform Platform, FStaticParameterSet& OutSet) const override
	{
		if (const FMaterialResource* Resource = MaterialInterface->GetMaterialResource(GMaxRHIFeatureLevel))
		{
			Resource->GetStaticParameterSet(Platform, OutSet);
		}
	}

	////////////////
	// FMaterialRenderProxy interface.

#if (ENGINE_MAJOR_VERSION > 4 || ENGINE_MINOR_VERSION >= 27)
	virtual const FMaterial* GetMaterialNoFallback(ERHIFeatureLevel::Type InFeatureLevel) const override
	{
		if (GetRenderingThreadShaderMap())
		{
			return this;
		}
		return nullptr;
	}

	virtual const FMaterialRenderProxy* GetFallback(ERHIFeatureLevel::Type InFeatureLevel) const override
	{
		return UMaterial::GetDefaultMaterial(MD_Surface)->GetRenderProxy();
	}
#else
	virtual const FMaterial& GetMaterialWithFallback(ERHIFeatureLevel::Type FeatureLevel, const FMaterialRenderProxy*& OutFallbackMaterialRenderProxy) const override
	{
		if(GetRenderingThreadShaderMap())
		{
			return *this;
		}
		else
		{
			OutFallbackMaterialRenderProxy = UMaterial::GetDefaultMaterial(MD_Surface)->GetRenderProxy();
			return OutFallbackMaterialRenderProxy->GetMaterialWithFallback(FeatureLevel, OutFallbackMaterialRenderProxy);
		}
	}
#endif

	virtual bool GetVectorValue(const FHashedMaterialParameterInfo& ParameterInfo, FLinearColor* OutValue, const FMaterialRenderContext& Context) const override
	{
		return MaterialInterface->GetRenderProxy()->GetVectorValue(ParameterInfo, OutValue, Context);
	}

	virtual bool GetScalarValue(const FHashedMaterialParameterInfo& ParameterInfo, float* OutValue, const FMaterialRenderContext& Context) const override
	{
		return MaterialInterface->GetRenderProxy()->GetScalarValue(ParameterInfo, OutValue, Context);
	}

	virtual bool GetTextureValue(const FHashedMaterialParameterInfo& ParameterInfo, const UTexture** OutValue, const FMaterialRenderContext& Context) const override
	{
		return MaterialInterface->GetRenderProxy()->GetTextureValue(ParameterInfo, OutValue, Context);
	}

	virtual bool GetTextureValue(const FHashedMaterialParameterInfo& ParameterInfo, const URuntimeVirtualTexture** OutValue, const FMaterialRenderContext& Context) const override
	{
		return MaterialInterface->GetRenderProxy()->GetTextureValue(ParameterInfo, OutValue, Context);
	}

	// Material properties.
	/** Entry point for compiling a specific material property.  This must call SetMaterialProperty. */
	virtual int32 CompilePropertyAndSetMaterialProperty(EMaterialProperty Property, FMaterialCompiler* Compiler, EShaderFrequency OverrideShaderFrequency, bool bUsePreviousFrameTime) const override
	{
		// needs to be called in this function!!
		Compiler->SetMaterialProperty(Property, OverrideShaderFrequency, bUsePreviousFrameTime);
		const int32 Ret = CompilePropertyAndSetMaterialPropertyWithoutCast(Property, Compiler);
		return Compiler->ForceCast(Ret, FMaterialAttributeDefinitionMap::GetValueType(Property), MFCF_ExactMatch | MFCF_ReplicateValue);
	}

	/** helper for CompilePropertyAndSetMaterialProperty() */
	int32 CompilePropertyAndSetMaterialPropertyWithoutCast(EMaterialProperty Property, FMaterialCompiler* Compiler) const
	{
		if (Property == MP_EmissiveColor)
		{
			const EBlendMode BlendMode = MaterialInterface->GetBlendMode();
			FGLTFExportMaterialCompiler ProxyCompiler(Compiler);
			const uint32 ForceCast_Exact_Replicate = MFCF_ForceCast | MFCF_ExactMatch | MFCF_ReplicateValue;

			switch (PropertyToCompile)
			{
			case MP_EmissiveColor:
				// Emissive is ALWAYS returned...
				return MaterialInterface->CompileProperty(&ProxyCompiler, MP_EmissiveColor, ForceCast_Exact_Replicate);
			case MP_BaseColor:
				return MaterialInterface->CompileProperty(&ProxyCompiler, MP_BaseColor, ForceCast_Exact_Replicate);
				break;
			case MP_Specular:
			case MP_Roughness:
			case MP_Anisotropy:
			case MP_Metallic:
			case MP_AmbientOcclusion:
				// Only return for Opaque and Masked...
				if (BlendMode == BLEND_Opaque || BlendMode == BLEND_Masked)
				{
					return MaterialInterface->CompileProperty(&ProxyCompiler, PropertyToCompile, ForceCast_Exact_Replicate);
				}
				break;

			case MP_Opacity:
			case MP_OpacityMask:
			case MP_SubsurfaceColor:
			case MP_CustomData0:
			case MP_CustomData1:
			{
				return MaterialInterface->CompileProperty(&ProxyCompiler, PropertyToCompile, ForceCast_Exact_Replicate);
			}
			case MP_Normal:
			case MP_Tangent:
				// Only return for Opaque and Masked...
				if (BlendMode == BLEND_Opaque || BlendMode == BLEND_Masked)
				{
					return CompileNormalEncoding(
						&ProxyCompiler,
						CompileNormalTransform(&ProxyCompiler, MaterialInterface->CompileProperty(&ProxyCompiler, PropertyToCompile, ForceCast_Exact_Replicate)));
				}
				break;
			case MP_Refraction:
					// Only return for Translucent, Additive, and AlphaComposite...
					if (BlendMode == BLEND_Translucent || BlendMode == BLEND_Additive || BlendMode == BLEND_AlphaComposite)
					{
						return CompileRefractionEncoding(
							Compiler,
							MaterialInterface->CompileProperty(&ProxyCompiler, MP_Refraction, ForceCast_Exact_Replicate));
					}
				break;
			case MP_ShadingModel:
				return CompileShadingModelEncoding(Compiler, MaterialInterface->CompileProperty(&ProxyCompiler, MP_ShadingModel));
			case MP_CustomOutput:
				 // NOTE: Currently we can assume input index is always 0, which it is for all custom outputs that are registered as material attributes
				return CompileInputForCustomOutput(&ProxyCompiler, 0, ForceCast_Exact_Replicate);
			default:
				return Compiler->Constant(1.0f);
			}

			return Compiler->Constant(0.0f);
		}
		else if (Property == MP_WorldPositionOffset)
		{
			//This property MUST return 0 as a default or during the process of rendering textures out for lightmass to use, pixels will be off by 1.
			return Compiler->Constant(0.0f);
		}
		else if (Property >= MP_CustomizedUVs0 && Property <= MP_CustomizedUVs7)
		{
			// Pass through customized UVs
			return MaterialInterface->CompileProperty(Compiler, Property);
		}
		else if (Property == MP_ShadingModel)
		{
			return MaterialInterface->CompileProperty(Compiler, MP_ShadingModel);

		}
		else
		{
			return Compiler->Constant(1.0f);
		}
	}

	virtual FString GetMaterialUsageDescription() const override
	{
		return FString::Printf(TEXT("MaterialBaking_%s"), MaterialInterface ? *MaterialInterface->GetName() : TEXT("NULL"));
	}
	virtual EMaterialDomain GetMaterialDomain() const override
	{
		// Because the baking module applies the material to a plane (or mesh),
		// it needs to be a surface material.
		return MD_Surface;
	}
	virtual bool IsTwoSided() const  override
	{
		if (MaterialInterface)
		{
			return MaterialInterface->IsTwoSided();
		}
		return false;
	}
	virtual bool IsDitheredLODTransition() const  override
	{
		if (MaterialInterface)
		{
			return MaterialInterface->IsDitheredLODTransition();
		}
		return false;
	}
	virtual bool IsLightFunction() const override
	{
		if (Material)
		{
			return (Material->MaterialDomain == MD_LightFunction);
		}
		return false;
	}
	virtual bool IsDeferredDecal() const override
	{
		// Decals are tricky. Since they mix with the underlying material
		// and can't be applied to meshes, they can't really be baked 1:1.
		// Instead we'll just bake them as surface materials.
		return false;
	}
	virtual bool IsVolumetricPrimitive() const override
	{
		return Material && Material->MaterialDomain == MD_Volume;
	}
	virtual bool IsSpecialEngineMaterial() const override
	{
		if (Material)
		{
			return (Material->bUsedAsSpecialEngineMaterial == 1);
		}
		return false;
	}
	virtual bool IsWireframe() const override
	{
		if (Material)
		{
			return (Material->Wireframe == 1);
		}
		return false;
	}
	virtual bool IsMasked() const override { return ProxyBlendMode == BLEND_Masked; }
	virtual enum EBlendMode GetBlendMode() const override { return ProxyBlendMode; }
	virtual FMaterialShadingModelField GetShadingModels() const override { return ProxyBlendMode == BLEND_Opaque ? MSM_DefaultLit : MSM_Unlit; }
	virtual bool IsShadingModelFromMaterialExpression() const override { return false; }
	virtual float GetOpacityMaskClipValue() const override { return 0.5f; }
	virtual bool GetCastDynamicShadowAsMasked() const override { return false; }
	virtual FString GetFriendlyName() const override { return FString::Printf(TEXT("FExportMaterialRenderer %s"), MaterialInterface ? *MaterialInterface->GetName() : TEXT("NULL")); }
	/**
	* Should shaders compiled for this material be saved to disk?
	*/
	virtual bool IsPersistent() const override { return true; }
	virtual FGuid GetMaterialId() const override { return Id; }

	virtual UMaterialInterface* GetMaterialInterface() const override
	{
		return MaterialInterface;
	}

	friend FArchive& operator<< (FArchive& Ar, FGLTFExportMaterialProxy& V)
	{
		return Ar << V.MaterialInterface;
	}

	/**
	* Iterate through all textures used by the material and return the maximum texture resolution used
	* (ideally this could be made dependent of the material property)
	*
	* @param MaterialInterface The material to scan for texture size
	*
	* @return Size (width and height)
	*/
	FIntPoint FindMaxTextureSize(UMaterialInterface* InMaterialInterface, FIntPoint MinimumSize = FIntPoint(1, 1)) const
	{
		// static lod settings so that we only initialize them once
		const UTextureLODSettings* GameTextureLODSettings = UDeviceProfileManager::Get().GetActiveProfile()->GetTextureLODSettings();

		TArray<UTexture*> MaterialTextures;
		InMaterialInterface->GetUsedTextures(MaterialTextures, EMaterialQualityLevel::Num, false, GMaxRHIFeatureLevel, false);

		// find the largest texture in the list (applying it's LOD bias)
		FIntPoint MaxSize = MinimumSize;
		for (int32 TexIndex = 0; TexIndex < MaterialTextures.Num(); TexIndex++)
		{
			const UTexture* Texture = MaterialTextures[TexIndex];

			if (Texture == NULL)
			{
				continue;
			}

			// get the max size of the texture
			const FIntPoint LocalSize = [&]()
			{
				if (Texture->IsA(UTexture2D::StaticClass()))
				{
					UTexture2D* Tex2D = (UTexture2D*)Texture;
					return FIntPoint(Tex2D->GetSizeX(), Tex2D->GetSizeY());
				}
				else if (Texture->IsA(UTextureCube::StaticClass()))
				{
					UTextureCube* TexCube = (UTextureCube*)Texture;
					return FIntPoint(TexCube->GetSizeX(), TexCube->GetSizeY());
				}
				else if (Texture->IsA(UTexture2DArray::StaticClass())) 
				{
					UTexture2DArray* TexArray = (UTexture2DArray*)Texture;
					return FIntPoint(TexArray->GetSizeX(), TexArray->GetSizeY());
				}
				return FIntPoint(0, 0);
			}();
			
			// bias the texture size based on LOD group
			const int32 LocalBias = GameTextureLODSettings->CalculateLODBias(Texture);
			MaxSize.X = FMath::Max(LocalSize.X >> LocalBias, MaxSize.X);
			MaxSize.Y = FMath::Max(LocalSize.Y >> LocalBias, MaxSize.Y);
		}

		return MaxSize;
	}

	static bool WillFillData(EBlendMode InBlendMode, EMaterialProperty InMaterialProperty)
	{
		if (InMaterialProperty == MP_EmissiveColor)
		{
			return true;
		}

		switch (InBlendMode)
		{
		case BLEND_Opaque:
		{
			switch (InMaterialProperty)
			{
			case MP_BaseColor:				return true;
			case MP_Specular:				return true;
			case MP_Normal:					return true;
			case MP_Tangent:				return true;
			case MP_Metallic:				return true;
			case MP_Roughness:				return true;
			case MP_Anisotropy:				return true;
			case MP_AmbientOcclusion:		return true;
			}
		}
		break;
		}
		return false;
	}

	virtual bool IsUsedWithStaticLighting() const override
	{
		return true; 
	}

	virtual void GatherExpressionsForCustomInterpolators(TArray<UMaterialExpression*>& OutExpressions) const override
	{
		if(Material)
		{
			Material->GetAllExpressionsForCustomInterpolators(OutExpressions);
		}
	}

private:
	int32 CompileInputForCustomOutput(FMaterialCompiler* Compiler, int32 InputIndex, uint32 ForceCastFlags) const
	{
		TArray<FMaterialCustomOutputAttributeDefintion> CustomAttributes;
		FMaterialAttributeDefinitionMap::GetCustomAttributeList(CustomAttributes);
		FMaterialCustomOutputAttributeDefintion* CustomAttribute = CustomAttributes.FindByPredicate([this](const FMaterialCustomOutputAttributeDefintion& Attribute) -> bool
		{
			return Attribute.AttributeName == CustomOutputToCompile;
		});
		check(CustomAttribute != nullptr);

		UMaterialExpressionCustomOutput* Expression = GetCustomOutputExpression(CustomAttribute->FunctionName);
		FExpressionInput* ExpressionInput = Expression ? Expression->GetInput(InputIndex) : nullptr;
		int32 Result = INDEX_NONE;

		if (ExpressionInput)
		{
			Result = ExpressionInput->Compile(Compiler);
		}
		else
		{
			Result = FMaterialAttributeDefinitionMap::CompileDefaultExpression(Compiler, CustomAttribute->AttributeID);
		}

		if (CustomOutputToCompile == TEXT("ClearCoatBottomNormal"))
		{
			Result = CompileNormalEncoding(Compiler, CompileNormalTransform(Compiler, Result));
		}

		if (ForceCastFlags & MFCF_ForceCast)
		{
			Result = Compiler->ForceCast(Result,  CustomAttribute->ValueType, ForceCastFlags);
		}

		return Result;
	}

	UMaterialExpressionCustomOutput* GetCustomOutputExpression(const FString& FunctionName) const
	{
		for (UMaterialExpression* Expression : Material->Expressions)
		{
			UMaterialExpressionCustomOutput* CustomOutputExpression = Cast<UMaterialExpressionCustomOutput>(Expression);
			if (CustomOutputExpression && CustomOutputExpression->GetFunctionName() == FunctionName)
			{
				return CustomOutputExpression;
			}
		}

		return nullptr;
	}

	int32 CompileNormalTransform(FMaterialCompiler* Compiler, int32 NormalInput) const
	{
		return bTangentSpaceNormal && !Material->bTangentSpaceNormal
			? Compiler->TransformVector(MCB_World, MCB_Tangent, NormalInput) : NormalInput;
	}

	int32 CompileNormalEncoding(FMaterialCompiler* Compiler, int32 NormalInput) const
	{
		return Compiler->Add(
			Compiler->Mul(NormalInput, Compiler->Constant(0.5f)), // [-1,1] * 0.5
			Compiler->Constant(0.5f)); // [-0.5,0.5] + 0.5
	}

	static int32 CompileRefractionEncoding(FMaterialCompiler* Compiler, int32 RefractionInput)
	{
		// NOTE: avoid getting yellow output (since value type in the attribute definition is incorrectly set to MCT_Float2)
		RefractionInput = Compiler->ForceCast(RefractionInput, MCT_Float1);

		// [1,Infinity] -> [1,0]
		return Compiler->Div(
			Compiler->Constant(1.0f),
			RefractionInput);
	}

	static int32 CompileShadingModelEncoding(FMaterialCompiler* Compiler, int32 ShadingModelInput)
	{
		class FMaterialCompilerHack : public FHLSLMaterialTranslator
		{
			using FHLSLMaterialTranslator::FHLSLMaterialTranslator;

		public:

			int32 ForceCastToFloat(int32 Index)
			{
				const FString Code = FString::Printf(TEXT("((float)(%s))"), *GetParameterCode(Index));
				const char* Buffer = static_cast<const char*>(static_cast<const void*>(*Code));
				const uint64 Hash = CityHash64(Buffer, Code.Len() * sizeof(TCHAR));
				const int32 CodeIndex = CurrentScopeChunks->Num();
				new(*CurrentScopeChunks) FShaderCodeChunk(Hash, *Code, TEXT(""), MCT_Float1, true);
				return CodeIndex;
			}
		};

		// [0,MSM_NUM] -> [0,1]
		return Compiler->Div(
			// NOTE: ugly hack to workaround casting shading model (uint) to float
			ShadingModelInput = static_cast<FMaterialCompilerHack*>(Compiler)->ForceCastToFloat(ShadingModelInput),
			Compiler->Constant(MSM_NUM));
	}

private:
	/** The material interface for this proxy */
	UMaterialInterface* MaterialInterface;
	UMaterial* Material;
	TArray<UObject*> ReferencedTextures;
	/** The property to compile for rendering the sample */
	EMaterialProperty PropertyToCompile;
	/** The name of the specific custom output to compile for rendering the sample. Only used if PropertyToCompile is MP_CustomOutput */
	FString CustomOutputToCompile;
	FGuid Id;
	bool bSynchronousCompilation;

public:
	/** The blend mode used when baking the proxy material */
	EBlendMode ProxyBlendMode;
	/** Whether to transform normals from world-space to tangent-space (does nothing if material already uses tangent-space normals) */
	bool bTangentSpaceNormal;
};
