// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Core/GLTFVector.h"
#include "Core/GLTFColor.h"
#include "Core/GLTFMatrix.h"
#include "Core/GLTFQuaternion.h"
#include "Json/GLTFJsonEnums.h"
#include "Engine/EngineTypes.h"

enum class EGLTFCameraControlMode : unsigned char;

struct GLTFEXPORTER_API FGLTFCoreUtilities
{
	static float ConvertLength(const float Length, const float ConversionScale = 0.01);

	static FGLTFVector3 ConvertVector(const FVector& Vector);

	static FGLTFVector3 ConvertPosition(const FVector& Position, const float ConversionScale = 0.01);

	static FGLTFVector3 ConvertScale(const FVector& Scale);

	static FGLTFVector3 ConvertNormal(const FVector& Normal);
	static FGLTFInt16Vector4 ConvertNormal(const FPackedRGBA16N& Normal);
	static FGLTFInt8Vector4 ConvertNormal(const FPackedNormal& Normal);

	static FGLTFVector4 ConvertTangent(const FVector& Tangent);
	static FGLTFInt16Vector4 ConvertTangent(const FPackedRGBA16N& Tangent);
	static FGLTFInt8Vector4 ConvertTangent(const FPackedNormal& Tangent);

	static FGLTFVector2 ConvertUV(const FVector2D& UV);
	static FGLTFVector2 ConvertUV(const FVector2DHalf& UV);

	static FGLTFColor4 ConvertColor(const FLinearColor& Color, bool bForceLDR);
	static FGLTFColor3 ConvertColor3(const FLinearColor& Color, bool bForceLDR);
	static FGLTFUInt8Color4 ConvertColor(const FColor& Color);

	static FGLTFQuaternion ConvertRotation(const FRotator& Rotation);
	static FGLTFQuaternion ConvertRotation(const FQuat& Rotation);

	static FGLTFMatrix4 ConvertMatrix(const FMatrix& Matrix);

	static FGLTFMatrix4 ConvertTransform(const FTransform& Transform, const float ConversionScale = 0.01);

	static float ConvertFieldOfView(float FOVInDegrees, float AspectRatio);

	static float ConvertLightAngle(const float Angle);

	static FGLTFQuaternion GetLocalCameraRotation();
	static FGLTFQuaternion GetLocalLightRotation();

	static EGLTFJsonCameraType ConvertCameraType(ECameraProjectionMode::Type ProjectionMode);
	static EGLTFJsonLightType ConvertLightType(ELightComponentType ComponentType);

	static EGLTFJsonInterpolation ConvertInterpolation(const EAnimInterpolationType Type);

	static EGLTFJsonShadingModel ConvertShadingModel(EMaterialShadingModel ShadingModel);

	static EGLTFJsonAlphaMode ConvertAlphaMode(EBlendMode Mode);
	static EGLTFJsonBlendMode ConvertBlendMode(EBlendMode Mode);

	static EGLTFJsonTextureWrap ConvertWrap(TextureAddress Address);

	static EGLTFJsonTextureFilter ConvertMinFilter(TextureFilter Filter);
	static EGLTFJsonTextureFilter ConvertMagFilter(TextureFilter Filter);

	static EGLTFJsonTextureFilter ConvertMinFilter(TextureFilter Filter, TextureGroup LODGroup);
	static EGLTFJsonTextureFilter ConvertMagFilter(TextureFilter Filter, TextureGroup LODGroup);

	static EGLTFJsonCubeFace ConvertCubeFace(ECubeFace CubeFace);

	static EGLTFJsonCameraControlMode ConvertCameraControlMode(EGLTFCameraControlMode CameraMode);

	template <typename ComponentType>
	static EGLTFJsonComponentType GetComponentType()
	{
		if (TIsSame<ComponentType, int8  >::Value) return EGLTFJsonComponentType::Int8;
		if (TIsSame<ComponentType, uint8 >::Value) return EGLTFJsonComponentType::UInt8;
		if (TIsSame<ComponentType, int16 >::Value) return EGLTFJsonComponentType::Int16;
		if (TIsSame<ComponentType, uint16>::Value) return EGLTFJsonComponentType::UInt16;
		if (TIsSame<ComponentType, int32 >::Value) return EGLTFJsonComponentType::Int32;
		if (TIsSame<ComponentType, uint32>::Value) return EGLTFJsonComponentType::UInt32;
		if (TIsSame<ComponentType, float >::Value) return EGLTFJsonComponentType::Float;
		return EGLTFJsonComponentType::None;
	}
};
