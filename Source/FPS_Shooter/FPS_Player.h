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
#include "Components/TimelineComponent.h"


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

	//Components Player//
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* CameraFPS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "WeaponPlayer")
	UWeaponComponent* weaponComponentPlayer;


	//Actions player input//
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* MovementAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* SprintAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* CrouchAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* WeaponChangeAction;


	//Expose BP Variables//
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
	float sprintSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
	float normalSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	float lookSensibility;

	//Crouch//
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Crouch")
	FVector crouchEyeOffSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Crouch")
	float crouchSpeed;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerProperty")
	float maxHealth;

	UPROPERTY(BlueprintReadWrite, Category = "PlayerProperty")
	float currentHealth;

private:

	//Private Variables//
	bool isSprint;
	bool isJumping;
	bool isCrouched;
	float defaultHalfHeight;
	


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float damageAmount, struct FDamageEvent const& damageEvent, AController* eventInstigator, AActor* damageCauser) override;

	void OnStartCrouch(float halfHeightAdjust, float scaledHalfHeightAdjust) override;

	void OnEndCrouch(float halfHeightAdjust, float scaledHalfHeightAdjust) override;

	void CalcCamera(float DeltaTime, struct FMinimalViewInfo& OutResult) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "StatePlayer")
	void OnDying();

private:

	//Actions Method//
	void MovementPlayer(const FInputActionValue& valueInput);
	void LookPlayer(const FInputActionValue& valueInput);
	void SelectWeapon(const FInputActionValue& valueInput);
	void JumpPlayer(const FInputActionValue& valueInput);
	void Sprint(const FInputActionValue& valueInput);
	void CrouchPlayer(const FInputActionValue& valueInput);

	//Others Private Methods//

private:

	UFUNCTION(BlueprintCallable, Category = "WeaponPlayer")
	UWeaponComponent* GetWeaponComponentPlayer();


};
