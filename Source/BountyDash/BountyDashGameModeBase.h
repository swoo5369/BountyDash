// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "BountyDash.h"
#include "GameFramework/GameModeBase.h"
#include "BountyDashGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class BOUNTYDASH_API ABountyDashGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

private:
	UPROPERTY()
	float gameSpeed;

	UPROPERTY()
	int32 gameLevel;

public:
	ABountyDashGameModeBase();

	void CharScoreUp(unsigned int charScore);

	UFUNCTION()
	float GetInvGameSpeed();

	UFUNCTION()
	float GetGamespeed();

	UFUNCTION()
	int32 GetGameLevel();

protected:

	UPROPERTY(EditAnyWhere, BlueprintReadOnly)
	int32 numCoinsForSpeedIncrease;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	float gameSpeedIncrease;

};
