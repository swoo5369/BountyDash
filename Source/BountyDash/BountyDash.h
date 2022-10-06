// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

template<typename T>
T* GetCustomGameMode(UWorld* worldConText)
{
	return Cast<T>(worldConText->GetAuthGameMode());
}
