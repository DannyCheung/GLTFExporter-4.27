// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GLTFExporter/Public/Exporters/GLTFMaterialExporter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGLTFMaterialExporter() {}
// Cross Module References
	GLTFEXPORTER_API UClass* Z_Construct_UClass_UGLTFMaterialExporter_NoRegister();
	GLTFEXPORTER_API UClass* Z_Construct_UClass_UGLTFMaterialExporter();
	GLTFEXPORTER_API UClass* Z_Construct_UClass_UGLTFExporter();
	UPackage* Z_Construct_UPackage__Script_GLTFExporter();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
// End Cross Module References
	void UGLTFMaterialExporter::StaticRegisterNativesUGLTFMaterialExporter()
	{
	}
	UClass* Z_Construct_UClass_UGLTFMaterialExporter_NoRegister()
	{
		return UGLTFMaterialExporter::StaticClass();
	}
	struct Z_Construct_UClass_UGLTFMaterialExporter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DefaultPreviewMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DefaultPreviewMesh;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGLTFMaterialExporter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGLTFExporter,
		(UObject* (*)())Z_Construct_UPackage__Script_GLTFExporter,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGLTFMaterialExporter_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Exporters/GLTFMaterialExporter.h" },
		{ "ModuleRelativePath", "Public/Exporters/GLTFMaterialExporter.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGLTFMaterialExporter_Statics::NewProp_DefaultPreviewMesh_MetaData[] = {
		{ "ModuleRelativePath", "Public/Exporters/GLTFMaterialExporter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGLTFMaterialExporter_Statics::NewProp_DefaultPreviewMesh = { "DefaultPreviewMesh", nullptr, (EPropertyFlags)0x0040000000202000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGLTFMaterialExporter, DefaultPreviewMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UGLTFMaterialExporter_Statics::NewProp_DefaultPreviewMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGLTFMaterialExporter_Statics::NewProp_DefaultPreviewMesh_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGLTFMaterialExporter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGLTFMaterialExporter_Statics::NewProp_DefaultPreviewMesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGLTFMaterialExporter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGLTFMaterialExporter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGLTFMaterialExporter_Statics::ClassParams = {
		&UGLTFMaterialExporter::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UGLTFMaterialExporter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UGLTFMaterialExporter_Statics::PropPointers),
		0,
		0x001000A8u,
		METADATA_PARAMS(Z_Construct_UClass_UGLTFMaterialExporter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGLTFMaterialExporter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGLTFMaterialExporter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGLTFMaterialExporter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGLTFMaterialExporter, 2650972963);
	template<> GLTFEXPORTER_API UClass* StaticClass<UGLTFMaterialExporter>()
	{
		return UGLTFMaterialExporter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGLTFMaterialExporter(Z_Construct_UClass_UGLTFMaterialExporter, &UGLTFMaterialExporter::StaticClass, TEXT("/Script/GLTFExporter"), TEXT("UGLTFMaterialExporter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGLTFMaterialExporter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
