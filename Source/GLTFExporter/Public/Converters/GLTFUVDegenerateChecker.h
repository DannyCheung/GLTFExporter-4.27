// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Converters/GLTFConverter.h"
#include "Converters/GLTFIndexArray.h"

struct FMeshDescription;

class GLTFEXPORTER_API FGLTFUVDegenerateChecker : public TGLTFConverter<float, const FMeshDescription*, FGLTFIndexArray, int32>
{
protected:

	virtual void Sanitize(const FMeshDescription*& Description, FGLTFIndexArray& SectionIndices, int32& TexCoord) override;

	virtual float Convert(const FMeshDescription* Description, FGLTFIndexArray SectionIndices, int32 TexCoord) override;

private:

	static bool IsDegenerateTriangle(const TStaticArray<FVector2D, 3>& Points);
	static bool IsDegenerateTriangle(const TStaticArray<FVector, 3>& Points);
};
