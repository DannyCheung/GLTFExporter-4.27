// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GLTFExporter/Public/Options/GLTFProxyOptions.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGLTFProxyOptions() {}
// Cross Module References
	GLTFEXPORTER_API UClass* Z_Construct_UClass_UGLTFProxyOptions_NoRegister();
	GLTFEXPORTER_API UClass* Z_Construct_UClass_UGLTFProxyOptions();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_GLTFExporter();
	GLTFEXPORTER_API UEnum* Z_Construct_UEnum_GLTFExporter_EGLTFMaterialBakeSizePOT();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_TextureFilter();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_TextureAddress();
	GLTFEXPORTER_API UScriptStruct* Z_Construct_UScriptStruct_FGLTFOverrideMaterialBakeSettings();
	GLTFEXPORTER_API UEnum* Z_Construct_UEnum_GLTFExporter_EGLTFMaterialPropertyGroup();
// End Cross Module References
	DEFINE_FUNCTION(UGLTFProxyOptions::execResetToDefault)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ResetToDefault();
		P_NATIVE_END;
	}
	void UGLTFProxyOptions::StaticRegisterNativesUGLTFProxyOptions()
	{
		UClass* Class = UGLTFProxyOptions::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ResetToDefault", &UGLTFProxyOptions::execResetToDefault },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UGLTFProxyOptions_ResetToDefault_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGLTFProxyOptions_ResetToDefault_Statics::Function_MetaDataParams[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/Options/GLTFProxyOptions.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGLTFProxyOptions_ResetToDefault_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGLTFProxyOptions, nullptr, "ResetToDefault", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGLTFProxyOptions_ResetToDefault_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGLTFProxyOptions_ResetToDefault_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGLTFProxyOptions_ResetToDefault()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGLTFProxyOptions_ResetToDefault_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UGLTFProxyOptions_NoRegister()
	{
		return UGLTFProxyOptions::StaticClass();
	}
	struct Z_Construct_UClass_UGLTFProxyOptions_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bBakeMaterialInputs_MetaData[];
#endif
		static void NewProp_bBakeMaterialInputs_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bBakeMaterialInputs;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_DefaultMaterialBakeSize_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DefaultMaterialBakeSize_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_DefaultMaterialBakeSize;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DefaultMaterialBakeFilter_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_DefaultMaterialBakeFilter;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DefaultMaterialBakeTiling_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_DefaultMaterialBakeTiling;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_DefaultInputBakeSettings_ValueProp;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_DefaultInputBakeSettings_Key_KeyProp_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_DefaultInputBakeSettings_Key_KeyProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DefaultInputBakeSettings_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_DefaultInputBakeSettings;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGLTFProxyOptions_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_GLTFExporter,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UGLTFProxyOptions_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UGLTFProxyOptions_ResetToDefault, "ResetToDefault" }, // 118360251
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGLTFProxyOptions_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "HideCategories", "DebugProperty" },
		{ "IncludePath", "Options/GLTFProxyOptions.h" },
		{ "ModuleRelativePath", "Public/Options/GLTFProxyOptions.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_bBakeMaterialInputs_MetaData[] = {
		{ "Category", "Material" },
		{ "Comment", "/** If enabled, a material input may be baked out to a texture (using a simple quad). Baking is only used for non-trivial material inputs (i.e. not simple texture or constant expressions). */" },
		{ "ModuleRelativePath", "Public/Options/GLTFProxyOptions.h" },
		{ "ToolTip", "If enabled, a material input may be baked out to a texture (using a simple quad). Baking is only used for non-trivial material inputs (i.e. not simple texture or constant expressions)." },
	};
#endif
	void Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_bBakeMaterialInputs_SetBit(void* Obj)
	{
		((UGLTFProxyOptions*)Obj)->bBakeMaterialInputs = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_bBakeMaterialInputs = { "bBakeMaterialInputs", nullptr, (EPropertyFlags)0x0010000000004005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UGLTFProxyOptions), &Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_bBakeMaterialInputs_SetBit, METADATA_PARAMS(Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_bBakeMaterialInputs_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_bBakeMaterialInputs_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_DefaultMaterialBakeSize_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_DefaultMaterialBakeSize_MetaData[] = {
		{ "Category", "Material" },
		{ "Comment", "/** Default size of the baked out texture (containing the material input). Can be overridden by material- and input-specific bake settings, see GLTFMaterialExportOptions. */" },
		{ "EditCondition", "bBakeMaterialInputs" },
		{ "ModuleRelativePath", "Public/Options/GLTFProxyOptions.h" },
		{ "ToolTip", "Default size of the baked out texture (containing the material input). Can be overridden by material- and input-specific bake settings, see GLTFMaterialExportOptions." },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_DefaultMaterialBakeSize = { "DefaultMaterialBakeSize", nullptr, (EPropertyFlags)0x0010000000004005, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGLTFProxyOptions, DefaultMaterialBakeSize), Z_Construct_UEnum_GLTFExporter_EGLTFMaterialBakeSizePOT, METADATA_PARAMS(Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_DefaultMaterialBakeSize_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_DefaultMaterialBakeSize_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_DefaultMaterialBakeFilter_MetaData[] = {
		{ "Category", "Material" },
		{ "Comment", "/** Default filtering mode used when sampling the baked out texture. Can be overridden by material- and input-specific bake settings, see GLTFMaterialExportOptions. */" },
		{ "EditCondition", "bBakeMaterialInputs" },
		{ "ModuleRelativePath", "Public/Options/GLTFProxyOptions.h" },
		{ "ToolTip", "Default filtering mode used when sampling the baked out texture. Can be overridden by material- and input-specific bake settings, see GLTFMaterialExportOptions." },
		{ "ValidEnumValues", "TF_Nearest, TF_Bilinear, TF_Trilinear" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_DefaultMaterialBakeFilter = { "DefaultMaterialBakeFilter", nullptr, (EPropertyFlags)0x0010000000004005, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGLTFProxyOptions, DefaultMaterialBakeFilter), Z_Construct_UEnum_Engine_TextureFilter, METADATA_PARAMS(Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_DefaultMaterialBakeFilter_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_DefaultMaterialBakeFilter_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_DefaultMaterialBakeTiling_MetaData[] = {
		{ "Category", "Material" },
		{ "Comment", "/** Default addressing mode used when sampling the baked out texture. Can be overridden by material- and input-specific bake settings, see GLTFMaterialExportOptions. */" },
		{ "EditCondition", "bBakeMaterialInputs" },
		{ "ModuleRelativePath", "Public/Options/GLTFProxyOptions.h" },
		{ "ToolTip", "Default addressing mode used when sampling the baked out texture. Can be overridden by material- and input-specific bake settings, see GLTFMaterialExportOptions." },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_DefaultMaterialBakeTiling = { "DefaultMaterialBakeTiling", nullptr, (EPropertyFlags)0x0010000000004005, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGLTFProxyOptions, DefaultMaterialBakeTiling), Z_Construct_UEnum_Engine_TextureAddress, METADATA_PARAMS(Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_DefaultMaterialBakeTiling_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_DefaultMaterialBakeTiling_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_DefaultInputBakeSettings_ValueProp = { "DefaultInputBakeSettings", nullptr, (EPropertyFlags)0x0000000000004001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, Z_Construct_UScriptStruct_FGLTFOverrideMaterialBakeSettings, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_DefaultInputBakeSettings_Key_KeyProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_DefaultInputBakeSettings_Key_KeyProp = { "DefaultInputBakeSettings_Key", nullptr, (EPropertyFlags)0x0000000000004001, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UEnum_GLTFExporter_EGLTFMaterialPropertyGroup, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_DefaultInputBakeSettings_MetaData[] = {
		{ "Category", "Material" },
		{ "Comment", "/** Input-specific default bake settings that override the general defaults above. */" },
		{ "EditCondition", "bBakeMaterialInputs" },
		{ "ModuleRelativePath", "Public/Options/GLTFProxyOptions.h" },
		{ "ToolTip", "Input-specific default bake settings that override the general defaults above." },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_DefaultInputBakeSettings = { "DefaultInputBakeSettings", nullptr, (EPropertyFlags)0x0010000000004005, UE4CodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGLTFProxyOptions, DefaultInputBakeSettings), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_DefaultInputBakeSettings_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_DefaultInputBakeSettings_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGLTFProxyOptions_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_bBakeMaterialInputs,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_DefaultMaterialBakeSize_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_DefaultMaterialBakeSize,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_DefaultMaterialBakeFilter,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_DefaultMaterialBakeTiling,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_DefaultInputBakeSettings_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_DefaultInputBakeSettings_Key_KeyProp_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_DefaultInputBakeSettings_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGLTFProxyOptions_Statics::NewProp_DefaultInputBakeSettings,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGLTFProxyOptions_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGLTFProxyOptions>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGLTFProxyOptions_Statics::ClassParams = {
		&UGLTFProxyOptions::StaticClass,
		"EditorPerProjectUserSettings",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UGLTFProxyOptions_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UGLTFProxyOptions_Statics::PropPointers),
		0,
		0x001000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UGLTFProxyOptions_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGLTFProxyOptions_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGLTFProxyOptions()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGLTFProxyOptions_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGLTFProxyOptions, 919289227);
	template<> GLTFEXPORTER_API UClass* StaticClass<UGLTFProxyOptions>()
	{
		return UGLTFProxyOptions::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGLTFProxyOptions(Z_Construct_UClass_UGLTFProxyOptions, &UGLTFProxyOptions::StaticClass, TEXT("/Script/GLTFExporter"), TEXT("UGLTFProxyOptions"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGLTFProxyOptions);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
