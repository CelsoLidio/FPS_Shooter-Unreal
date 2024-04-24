// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubSystems.h"
#include "PrintStrings.h"
#include "WeaponComponent.h"

#include "FPS_Player.generated.h"

class UInputAction;
class UInputMappingContext;

UCLASS()
class FPS_SHOOTER_API AFPS_Player : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPS_Player();

	//Camera Character//
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* CameraFPS;

	//Actions player input//
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* MovementAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* WeaponChangeAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "WeaponPlayer")
	UWeaponComponent* weaponComponentPlayer;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category= "Camera")
	float lookSensibility;

private:

	


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	//Actions Method//
	void MovementPlayer(const FInputActionValue& valueInput);
	void LookPlayer(const FInputActionValue& valueInput);
	void SelectWeapon(const FInputActionValue& valueInput);


private:

	UFUNCTION(BlueprintCallable, Category = "WeaponPlayer")
	UWeaponComponent* GetWeaponComponentPlayer();

};
