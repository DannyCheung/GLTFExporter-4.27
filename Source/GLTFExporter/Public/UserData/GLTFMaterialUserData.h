// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Engine/Texture.h"
#include "Engine/AssetUserData.h"
#include "GLTFMaterialUserData.generated.h"

class UMaterialInterface;

UENUM(BlueprintType)
enum class EGLTFMaterialBakeMode : uint8
{
	/** Never bake material inputs. */
	Disabled,
	/** Only use a simple quad if a material input needs to be baked out. */
	Simple,
	/** Allow usage of the mesh data if a material input needs to be baked out with vertex data. */
	UseMeshData,
};

UENUM(BlueprintType)
enum class EGLTFMaterialBakeSizePOT : uint8
{
	POT_1 UMETA(DisplayName = "1 x 1"),
	POT_2 UMETA(DisplayName = "2 x 2"),
	POT_4 UMETA(DisplayName = "4 x 4"),
	POT_8 UMETA(DisplayName = "8 x 8"),
	POT_16 UMETA(DisplayName = "16 x 16"),
	POT_32 UMETA(DisplayName = "32 x 32"),
	POT_64 UMETA(DisplayName = "64 x 64"),
	POT_128 UMETA(DisplayName = "128 x 128"),
	POT_256 UMETA(DisplayName = "256 x 256"),
	POT_512 UMETA(DisplayName = "512 x 512"),
	POT_1024 UMETA(DisplayName = "1024 x 1024"),
	POT_2048 UMETA(DisplayName = "2048 x 2048"),
	POT_4096 UMETA(DisplayName = "4096 x 4096"),
	POT_8192 UMETA(DisplayName = "8192 x 8192")
};

UENUM(BlueprintType)
enum class EGLTFMaterialPropertyGroup : uint8
{
	None UMETA(DisplayName = "None"),

	BaseColorOpacity UMETA(DisplayName = "Base Color + Opacity (Mask)"),
	MetallicRoughness UMETA(DisplayName = "Metallic + Roughness"),
	EmissiveColor UMETA(DisplayName = "Emissive Color"),
	Normal UMETA(DisplayName = "Normal"),
	AmbientOcclusion UMETA(DisplayName = "Ambient Occlusion"),
	ClearCoatRoughness UMETA(DisplayName = "Clear Coat + Clear Coat Roughness"),
	ClearCoatBottomNormal UMETA(DisplayName = "Clear Coat Bottom Normal"),
};

USTRUCT(Blueprintable)
struct FGLTFOverrideMaterialBakeSettings
{
	GENERATED_BODY()

	FGLTFOverrideMaterialBakeSettings();

	/** If enabled, default size will be overridden by the corresponding property. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "", meta = (InlineEditConditionToggle))
	bool bOverrideSize;

	/** Overrides default size of the baked out texture. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "", meta = (EditCondition = "bOverrideSize"))
	EGLTFMaterialBakeSizePOT Size;

	/** If enabled, default filtering mode will be overridden by the corresponding property. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "", meta = (InlineEditConditionToggle))
	bool bOverrideFilter;

	/** Overrides the default filtering mode used when sampling the baked out texture. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "", meta = (EditCondition = "bOverrideFilter", ValidEnumValues = "TF_Nearest, TF_Bilinear, TF_Trilinear"))
	TEnumAsByte<TextureFilter> Filter;

	/** If enabled, default addressing mode will be overridden by the corresponding property. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "", meta = (InlineEditConditionToggle))
	bool bOverrideTiling;

	/** Overrides the default addressing mode used when sampling the baked out texture. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "", meta = (EditCondition = "bOverrideTiling"))
	TEnumAsByte<TextureAddress> Tiling;
};

/** glTF-specific user data that can be added to material assets to override export options */
UCLASS(BlueprintType, meta = (DisplayName = "GLTF Material Export Options"))
class GLTFEXPORTER_API UGLTFMaterialExportOptions : public UAssetUserData
{
	GENERATED_BODY()

public:

	// TODO: add support for overriding more export options

	/** If assigned, export will use the proxy instead of the original material. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
	UMaterialInterface* Proxy;

	/** Default bake settings for this material in general. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Override Bake Settings", meta = (ShowOnlyInnerProperties))
	FGLTFOverrideMaterialBakeSettings Default;

	/** Input-specific bake settings that override the defaults above. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Override Bake Settings")
	TMap<EGLTFMaterialPropertyGroup, FGLTFOverrideMaterialBakeSettings> Inputs;

	static const UMaterialInterface* ResolveProxy(const UMaterialInterface* Material);

	static EGLTFMaterialBakeSizePOT GetBakeSizeForPropertyGroup(const UMaterialInterface* Material, EGLTFMaterialPropertyGroup PropertyGroup, EGLTFMaterialBakeSizePOT DefaultValue);
	static TextureFilter GetBakeFilterForPropertyGroup(const UMaterialInterface* Material, EGLTFMaterialPropertyGroup PropertyGroup, TextureFilter DefaultValue);
	static TextureAddress GetBakeTilingForPropertyGroup(const UMaterialInterface* Material, EGLTFMaterialPropertyGroup PropertyGroup, TextureAddress DefaultValue);

private:

	template <typename Predicate>
	static const FGLTFOverrideMaterialBakeSettings* GetBakeSettingsByPredicate(const UMaterialInterface* Material, EGLTFMaterialPropertyGroup PropertyGroup, Predicate Pred);
};
