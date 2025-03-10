// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

struct FGLTFBufferUtility
{
	static bool HasCPUAccess(const FRawStaticIndexBuffer* IndexBuffer);
	static bool HasCPUAccess(const FRawStaticIndexBuffer16or32Interface* IndexBuffer);
	static bool HasCPUAccess(const FPositionVertexBuffer* VertexBuffer);
	static bool HasCPUAccess(const FColorVertexBuffer* VertexBuffer);
	static bool HasCPUAccess(const FStaticMeshVertexBuffer* VertexBuffer);
	static bool HasCPUAccess(const FSkinWeightVertexBuffer* VertexBuffer);

	static const void* GetCPUBuffer(const FRawStaticIndexBuffer* IndexBuffer);
	static const void* GetCPUBuffer(const FRawStaticIndexBuffer16or32Interface* IndexBuffer);
	static const void* GetCPUBuffer(const FSkinWeightDataVertexBuffer* VertexBuffer);
	static const void* GetCPUBuffer(const FSkinWeightLookupVertexBuffer* VertexBuffer);

	static void ReadRHIBuffer(FRHIIndexBuffer* SourceBuffer, TArray<uint8>& OutData);
	static void ReadRHIBuffer(FRHIVertexBuffer* SourceBuffer, TArray<uint8>& OutData);
};
