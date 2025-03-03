// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GLTFExporter/Public/Exporters/GLTFExporter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGLTFExporter() {}
// Cross Module References
	GLTFEXPORTER_API UScriptStruct* Z_Construct_UScriptStruct_FGLTFExportMessages();
	UPackage* Z_Construct_UPackage__Script_GLTFExporter();
	GLTFEXPORTER_API UClass* Z_Construct_UClass_UGLTFExporter_NoRegister();
	GLTFEXPORTER_API UClass* Z_Construct_UClass_UGLTFExporter();
	ENGINE_API UClass* Z_Construct_UClass_UExporter();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	GLTFEXPORTER_API UClass* Z_Construct_UClass_UGLTFExportOptions_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
class UScriptStruct* FGLTFExportMessages::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern GLTFEXPORTER_API uint32 Get_Z_Construct_UScriptStruct_FGLTFExportMessages_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FGLTFExportMessages, Z_Construct_UPackage__Script_GLTFExporter(), TEXT("GLTFExportMessages"), sizeof(FGLTFExportMessages), Get_Z_Construct_UScriptStruct_FGLTFExportMessages_Hash());
	}
	return Singleton;
}
template<> GLTFEXPORTER_API UScriptStruct* StaticStruct<FGLTFExportMessages>()
{
	return FGLTFExportMessages::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FGLTFExportMessages(FGLTFExportMessages::StaticStruct, TEXT("/Script/GLTFExporter"), TEXT("GLTFExportMessages"), false, nullptr, nullptr);
static struct FScriptStruct_GLTFExporter_StaticRegisterNativesFGLTFExportMessages
{
	FScriptStruct_GLTFExporter_StaticRegisterNativesFGLTFExportMessages()
	{
		UScriptStruct::DeferCppStructOps<FGLTFExportMessages>(FName(TEXT("GLTFExportMessages")));
	}
} ScriptStruct_GLTFExporter_StaticRegisterNativesFGLTFExportMessages;
	struct Z_Construct_UScriptStruct_FGLTFExportMessages_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Suggestions_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Suggestions_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Suggestions;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Warnings_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Warnings_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Warnings;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Errors_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Errors_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Errors;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGLTFExportMessages_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Exporters/GLTFExporter.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FGLTFExportMessages_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGLTFExportMessages>();
	}
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FGLTFExportMessages_Statics::NewProp_Suggestions_Inner = { "Suggestions", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGLTFExportMessages_Statics::NewProp_Suggestions_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/Exporters/GLTFExporter.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FGLTFExportMessages_Statics::NewProp_Suggestions = { "Suggestions", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGLTFExportMessages, Suggestions), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FGLTFExportMessages_Statics::NewProp_Suggestions_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGLTFExportMessages_Statics::NewProp_Suggestions_MetaData)) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FGLTFExportMessages_Statics::NewProp_Warnings_Inner = { "Warnings", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGLTFExportMessages_Statics::NewProp_Warnings_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/Exporters/GLTFExporter.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FGLTFExportMessages_Statics::NewProp_Warnings = { "Warnings", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGLTFExportMessages, Warnings), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FGLTFExportMessages_Statics::NewProp_Warnings_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGLTFExportMessages_Statics::NewProp_Warnings_MetaData)) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FGLTFExportMessages_Statics::NewProp_Errors_Inner = { "Errors", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGLTFExportMessages_Statics::NewProp_Errors_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/Exporters/GLTFExporter.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FGLTFExportMessages_Statics::NewProp_Errors = { "Errors", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGLTFExportMessages, Errors), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FGLTFExportMessages_Statics::NewProp_Errors_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGLTFExportMessages_Statics::NewProp_Errors_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGLTFExportMessages_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGLTFExportMessages_Statics::NewProp_Suggestions_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGLTFExportMessages_Statics::NewProp_Suggestions,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGLTFExportMessages_Statics::NewProp_Warnings_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGLTFExportMessages_Statics::NewProp_Warnings,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGLTFExportMessages_Statics::NewProp_Errors_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGLTFExportMessages_Statics::NewProp_Errors,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGLTFExportMessages_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_GLTFExporter,
		nullptr,
		&NewStructOps,
		"GLTFExportMessages",
		sizeof(FGLTFExportMessages),
		alignof(FGLTFExportMessages),
		Z_Construct_UScriptStruct_FGLTFExportMessages_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGLTFExportMessages_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FGLTFExportMessages_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGLTFExportMessages_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FGLTFExportMessages()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FGLTFExportMessages_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_GLTFExporter();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("GLTFExportMessages"), sizeof(FGLTFExportMessages), Get_Z_Construct_UScriptStruct_FGLTFExportMessages_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FGLTFExportMessages_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FGLTFExportMessages_Hash() { return 3626485292U; }
	DEFINE_FUNCTION(UGLTFExporter::execExportToGLTF)
	{
		P_GET_OBJECT(UObject,Z_Param_Object);
		P_GET_PROPERTY(FStrProperty,Z_Param_FilePath);
		P_GET_OBJECT(UGLTFExportOptions,Z_Param_Options);
		P_GET_TSET_REF(AActor*,Z_Param_Out_SelectedActors);
		P_GET_STRUCT_REF(FGLTFExportMessages,Z_Param_Out_OutMessages);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UGLTFExporter::ExportToGLTF(Z_Param_Object,Z_Param_FilePath,Z_Param_Options,Z_Param_Out_SelectedActors,Z_Param_Out_OutMessages);
		P_NATIVE_END;
	}
	void UGLTFExporter::StaticRegisterNativesUGLTFExporter()
	{
		UClass* Class = UGLTFExporter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ExportToGLTF", &UGLTFExporter::execExportToGLTF },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UGLTFExporter_ExportToGLTF_Statics
	{
		struct GLTFExporter_eventExportToGLTF_Parms
		{
			UObject* Object;
			FString FilePath;
			const UGLTFExportOptions* Options;
			TSet<AActor*> SelectedActors;
			FGLTFExportMessages OutMessages;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Object;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FilePath_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_FilePath;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Options_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Options;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SelectedActors_ElementProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SelectedActors_MetaData[];
#endif
		static const UE4CodeGen_Private::FSetPropertyParams NewProp_SelectedActors;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_OutMessages;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGLTFExporter_ExportToGLTF_Statics::NewProp_Object = { "Object", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GLTFExporter_eventExportToGLTF_Parms, Object), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGLTFExporter_ExportToGLTF_Statics::NewProp_FilePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGLTFExporter_ExportToGLTF_Statics::NewProp_FilePath = { "FilePath", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GLTFExporter_eventExportToGLTF_Parms, FilePath), METADATA_PARAMS(Z_Construct_UFunction_UGLTFExporter_ExportToGLTF_Statics::NewProp_FilePath_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UGLTFExporter_ExportToGLTF_Statics::NewProp_FilePath_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGLTFExporter_ExportToGLTF_Statics::NewProp_Options_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGLTFExporter_ExportToGLTF_Statics::NewProp_Options = { "Options", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GLTFExporter_eventExportToGLTF_Parms, Options), Z_Construct_UClass_UGLTFExportOptions_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UGLTFExporter_ExportToGLTF_Statics::NewProp_Options_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UGLTFExporter_ExportToGLTF_Statics::NewProp_Options_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGLTFExporter_ExportToGLTF_Statics::NewProp_SelectedActors_ElementProp = { "SelectedActors", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGLTFExporter_ExportToGLTF_Statics::NewProp_SelectedActors_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FSetPropertyParams Z_Construct_UFunction_UGLTFExporter_ExportToGLTF_Statics::NewProp_SelectedActors = { "SelectedActors", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GLTFExporter_eventExportToGLTF_Parms, SelectedActors), METADATA_PARAMS(Z_Construct_UFunction_UGLTFExporter_ExportToGLTF_Statics::NewProp_SelectedActors_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UGLTFExporter_ExportToGLTF_Statics::NewProp_SelectedActors_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGLTFExporter_ExportToGLTF_Statics::NewProp_OutMessages = { "OutMessages", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GLTFExporter_eventExportToGLTF_Parms, OutMessages), Z_Construct_UScriptStruct_FGLTFExportMessages, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UGLTFExporter_ExportToGLTF_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((GLTFExporter_eventExportToGLTF_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGLTFExporter_ExportToGLTF_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(GLTFExporter_eventExportToGLTF_Parms), &Z_Construct_UFunction_UGLTFExporter_ExportToGLTF_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGLTFExporter_ExportToGLTF_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGLTFExporter_ExportToGLTF_Statics::NewProp_Object,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGLTFExporter_ExportToGLTF_Statics::NewProp_FilePath,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGLTFExporter_ExportToGLTF_Statics::NewProp_Options,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGLTFExporter_ExportToGLTF_Statics::NewProp_SelectedActors_ElementProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGLTFExporter_ExportToGLTF_Statics::NewProp_SelectedActors,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGLTFExporter_ExportToGLTF_Statics::NewProp_OutMessages,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGLTFExporter_ExportToGLTF_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGLTFExporter_ExportToGLTF_Statics::Function_MetaDataParams[] = {
		{ "Category", "Miscellaneous" },
		{ "ModuleRelativePath", "Public/Exporters/GLTFExporter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGLTFExporter_ExportToGLTF_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGLTFExporter, nullptr, "ExportToGLTF", nullptr, nullptr, sizeof(GLTFExporter_eventExportToGLTF_Parms), Z_Construct_UFunction_UGLTFExporter_ExportToGLTF_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGLTFExporter_ExportToGLTF_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGLTFExporter_ExportToGLTF_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGLTFExporter_ExportToGLTF_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGLTFExporter_ExportToGLTF()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGLTFExporter_ExportToGLTF_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UGLTFExporter_NoRegister()
	{
		return UGLTFExporter::StaticClass();
	}
	struct Z_Construct_UClass_UGLTFExporter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGLTFExporter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UExporter,
		(UObject* (*)())Z_Construct_UPackage__Script_GLTFExporter,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UGLTFExporter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UGLTFExporter_ExportToGLTF, "ExportToGLTF" }, // 4093685435
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGLTFExporter_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Exporters/GLTFExporter.h" },
		{ "ModuleRelativePath", "Public/Exporters/GLTFExporter.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGLTFExporter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGLTFExporter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGLTFExporter_Statics::ClassParams = {
		&UGLTFExporter::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A9u,
		METADATA_PARAMS(Z_Construct_UClass_UGLTFExporter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGLTFExporter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGLTFExporter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGLTFExporter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGLTFExporter, 2302971755);
	template<> GLTFEXPORTER_API UClass* StaticClass<UGLTFExporter>()
	{
		return UGLTFExporter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGLTFExporter(Z_Construct_UClass_UGLTFExporter, &UGLTFExporter::StaticClass, TEXT("/Script/GLTFExporter"), TEXT("UGLTFExporter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGLTFExporter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
