// Copyright Epic Games, Inc. All Rights Reserved.

#include "Converters/GLTFUVDegenerateChecker.h"
#if WITH_EDITOR
#include "StaticMeshAttributes.h"
#include "MeshDescription.h"
#endif

void FGLTFUVDegenerateChecker::Sanitize(const FMeshDescription*& Description, FGLTFIndexArray& SectionIndices, int32& TexCoord)
{
#if WITH_EDITOR
	if (Description != nullptr)
	{
		const int32 SectionCount = Description->PolygonGroups().Num();
		for (const int32 SectionIndex : SectionIndices)
		{
			if (SectionIndex < 0 || SectionIndex >= SectionCount)
			{
				Description = nullptr;
			}
		}
	}

	if (Description != nullptr)
	{
		const int32 TexCoordCount = Description->VertexInstanceAttributes().GetAttributesRef<FVector2D>(MeshAttribute::VertexInstance::TextureCoordinate).GetNumIndices();
		if (TexCoord < 0 || TexCoord >= TexCoordCount)
		{
			Description = nullptr;
		}
	}
#endif
}

float FGLTFUVDegenerateChecker::Convert(const FMeshDescription* Description, FGLTFIndexArray SectionIndices, int32 TexCoord)
{
#if WITH_EDITOR
	if (Description != nullptr)
	{
		const TVertexAttributesConstRef<FVector> Positions =
		Description->VertexAttributes().GetAttributesRef<FVector>(MeshAttribute::Vertex::Position);
		const TVertexInstanceAttributesConstRef<FVector2D> UVs =
			Description->VertexInstanceAttributes().GetAttributesRef<FVector2D>(MeshAttribute::VertexInstance::TextureCoordinate);

		int32 TriangleCount = 0;
		int32 DegenerateCount = 0;

		for (const int32 SectionIndex : SectionIndices)
		{
			for (const FPolygonID PolygonID : Description->GetPolygonGroupPolygons(FPolygonGroupID(SectionIndex)))
			{
				for (const FTriangleID TriangleID : Description->GetPolygonTriangleIDs(PolygonID))
				{
					const TStaticArray<FVertexID, 3> TriangleVertexIDs = Description->GetTriangleVertices(TriangleID);
					TArrayView<const FVertexInstanceID> TriangleVertexInstanceIDs = Description->GetTriangleVertexInstances(TriangleID);

					TStaticArray<FVector, 3> TrianglePositions;
					TStaticArray<FVector2D, 3> TriangleUVs;

					for (int32 Index = 0; Index < 3; Index++)
					{
						TrianglePositions[Index] = Positions.Get(TriangleVertexIDs[Index]);
						TriangleUVs[Index] = UVs.Get(TriangleVertexInstanceIDs[Index], TexCoord);
					}

					if (!IsDegenerateTriangle(TrianglePositions))
					{
						TriangleCount++;

						if (IsDegenerateTriangle(TriangleUVs))
						{
							DegenerateCount++;
						}
					}
				}
			}
		}

		if (TriangleCount == 0)
		{
			return -1;
		}

		if (TriangleCount == DegenerateCount)
		{
			return 1;
		}

		return static_cast<float>(DegenerateCount) / static_cast<float>(TriangleCount);
	}
#endif

	return -1;
}

bool FGLTFUVDegenerateChecker::IsDegenerateTriangle(const TStaticArray<FVector2D, 3>& Points)
{
	const FVector2D AB = Points[1] - Points[0];
	const FVector2D AC = Points[2] - Points[0];
	const float DoubleArea = FMath::Abs(AB ^ AC);
	return DoubleArea < 2 * SMALL_NUMBER;
}

bool FGLTFUVDegenerateChecker::IsDegenerateTriangle(const TStaticArray<FVector, 3>& Points)
{
	const FVector AB = Points[1] - Points[0];
	const FVector AC = Points[2] - Points[0];
	const float DoubleAreaSquared = (AB ^ AC).SizeSquared();
	return DoubleAreaSquared < 2 * SMALL_NUMBER * SMALL_NUMBER;
}
