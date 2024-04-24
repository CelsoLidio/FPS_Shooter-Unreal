// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputSubSystems.h"

#include "FPS_Controller.generated.h"

class UInputMappingContext;


UCLASS()
class FPS_SHOOTER_API AFPS_Controller : public APlayerController
{
	GENERATED_BODY()
	
protected:

	//Mapping Input//
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputMappingContext* PlayerMappingInput;


protected:

	virtual void BeginPlay() override;

public:

	UEnhancedInputLocalPlayerSubsystem* subsystemController;
};
