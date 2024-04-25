// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EnemyAI_Interface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UEnemyAI_Interface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */

UENUM(BlueprintType)
enum class EAIMoveSpeed : uint8
{
	Idle,
	Walking,
	Sprinting
};

class FPS_SHOOTER_API IEnemyAI_Interface
{
	GENERATED_BODY()



	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintCallable,BlueprintNativeEvent, Category = "EnemyAI")
	AActor* GetPatrolRoute();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "EnemyAI")
	float SetMovementSpeed(EAIMoveSpeed moveSpeedType);
};
