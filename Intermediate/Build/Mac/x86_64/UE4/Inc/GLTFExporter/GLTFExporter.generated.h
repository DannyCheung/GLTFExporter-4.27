// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
class UGLTFExportOptions;
class AActor;
struct FGLTFExportMessages;
#ifdef GLTFEXPORTER_GLTFExporter_generated_h
#error "GLTFExporter.generated.h already included, missing '#pragma once' in GLTFExporter.h"
#endif
#define GLTFEXPORTER_GLTFExporter_generated_h

#define HostProject_Plugins_GLTFExporter_Source_GLTFExporter_Public_Exporters_GLTFExporter_h_15_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FGLTFExportMessages_Statics; \
	GLTFEXPORTER_API static class UScriptStruct* StaticStruct();


template<> GLTFEXPORTER_API UScriptStruct* StaticStruct<struct FGLTFExportMessages>();

#define HostProject_Plugins_GLTFExporter_Source_GLTFExporter_Public_Exporters_GLTFExporter_h_32_SPARSE_DATA
#define HostProject_Plugins_GLTFExporter_Source_GLTFExporter_Public_Exporters_GLTFExporter_h_32_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execExportToGLTF);


#define HostProject_Plugins_GLTFExporter_Source_GLTFExporter_Public_Exporters_GLTFExporter_h_32_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execExportToGLTF);


#define HostProject_Plugins_GLTFExporter_Source_GLTFExporter_Public_Exporters_GLTFExporter_h_32_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGLTFExporter(); \
	friend struct Z_Construct_UClass_UGLTFExporter_Statics; \
public: \
	DECLARE_CLASS(UGLTFExporter, UExporter, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Transient), CASTCLASS_None, TEXT("/Script/GLTFExporter"), NO_API) \
	DECLARE_SERIALIZER(UGLTFExporter)


#define HostProject_Plugins_GLTFExporter_Source_GLTFExporter_Public_Exporters_GLTFExporter_h_32_INCLASS \
private: \
	static void StaticRegisterNativesUGLTFExporter(); \
	friend struct Z_Construct_UClass_UGLTFExporter_Statics; \
public: \
	DECLARE_CLASS(UGLTFExporter, UExporter, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Transient), CASTCLASS_None, TEXT("/Script/GLTFExporter"), NO_API) \
	DECLARE_SERIALIZER(UGLTFExporter)


#define HostProject_Plugins_GLTFExporter_Source_GLTFExporter_Public_Exporters_GLTFExporter_h_32_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGLTFExporter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGLTFExporter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGLTFExporter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGLTFExporter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGLTFExporter(UGLTFExporter&&); \
	NO_API UGLTFExporter(const UGLTFExporter&); \
public:


#define HostProject_Plugins_GLTFExporter_Source_GLTFExporter_Public_Exporters_GLTFExporter_h_32_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGLTFExporter(UGLTFExporter&&); \
	NO_API UGLTFExporter(const UGLTFExporter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGLTFExporter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGLTFExporter); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGLTFExporter)


#define HostProject_Plugins_GLTFExporter_Source_GLTFExporter_Public_Exporters_GLTFExporter_h_32_PRIVATE_PROPERTY_OFFSET
#define HostProject_Plugins_GLTFExporter_Source_GLTFExporter_Public_Exporters_GLTFExporter_h_27_PROLOG
#define HostProject_Plugins_GLTFExporter_Source_GLTFExporter_Public_Exporters_GLTFExporter_h_32_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_GLTFExporter_Source_GLTFExporter_Public_Exporters_GLTFExporter_h_32_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_GLTFExporter_Source_GLTFExporter_Public_Exporters_GLTFExporter_h_32_SPARSE_DATA \
	HostProject_Plugins_GLTFExporter_Source_GLTFExporter_Public_Exporters_GLTFExporter_h_32_RPC_WRAPPERS \
	HostProject_Plugins_GLTFExporter_Source_GLTFExporter_Public_Exporters_GLTFExporter_h_32_INCLASS \
	HostProject_Plugins_GLTFExporter_Source_GLTFExporter_Public_Exporters_GLTFExporter_h_32_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HostProject_Plugins_GLTFExporter_Source_GLTFExporter_Public_Exporters_GLTFExporter_h_32_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_GLTFExporter_Source_GLTFExporter_Public_Exporters_GLTFExporter_h_32_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_GLTFExporter_Source_GLTFExporter_Public_Exporters_GLTFExporter_h_32_SPARSE_DATA \
	HostProject_Plugins_GLTFExporter_Source_GLTFExporter_Public_Exporters_GLTFExporter_h_32_RPC_WRAPPERS_NO_PURE_DECLS \
	HostProject_Plugins_GLTFExporter_Source_GLTFExporter_Public_Exporters_GLTFExporter_h_32_INCLASS_NO_PURE_DECLS \
	HostProject_Plugins_GLTFExporter_Source_GLTFExporter_Public_Exporters_GLTFExporter_h_32_ENHANCED_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GLTFEXPORTER_API UClass* StaticClass<class UGLTFExporter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HostProject_Plugins_GLTFExporter_Source_GLTFExporter_Public_Exporters_GLTFExporter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
