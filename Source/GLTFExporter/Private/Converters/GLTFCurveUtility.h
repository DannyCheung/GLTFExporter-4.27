// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

class UCurveLinearColor;

struct FGLTFCurveUtility
{
	static bool HasAnyAdjustment(const UCurveLinearColor& ColorCurve, float Tolerance = KINDA_SMALL_NUMBER);
};
