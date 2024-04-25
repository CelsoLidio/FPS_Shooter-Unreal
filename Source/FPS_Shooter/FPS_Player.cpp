// Fill out your copyright notice in the Description page of Project Settings.


#include "FPS_Player.h"
#include "FPS_Controller.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AFPS_Player::AFPS_Player()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//Criando Camera FPS
	CameraFPS = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraFPS"));
	CameraFPS->SetupAttachment(GetCapsuleComponent());
	CameraFPS->bUsePawnControlRotation = true;

	weaponComponentPlayer = CreateDefaultSubobject<UWeaponComponent>(TEXT("WeaponPlayer"));
	weaponComponentPlayer->SetupAttachment(CameraFPS);
	weaponComponentPlayer->SetRelativeLocationAndRotation(FVector(50.0f, 0.0f, -160.0f), FRotator(0.0, -90.0, 0.0f));

	//Init Variables//
	lookSensibility = 70.0f;
	isSprint = false;
	isJumping = false;
	normalSpeed = 600.0f;
	sprintSpeed = 1000.0f;	
	
	crouchEyeOffSet = FVector::Zero();
	crouchSpeed = 100.0f;

	
}

// Called when the game starts or when spawned
void AFPS_Player::BeginPlay()
{
	Super::BeginPlay();


	TArray<USceneComponent*> allChildCamera;

	CameraFPS->GetChildrenComponents(false, allChildCamera);
	GetCharacterMovement()->MaxWalkSpeed = normalSpeed;
}



// Called every frame
void AFPS_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float crouchTime = FMath::Min(1.0f, crouchSpeed * DeltaTime);
	crouchEyeOffSet = (1.0f - crouchTime) * crouchEyeOffSet;
}

// Called to bind functionality to input
void AFPS_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* enhancedInput = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		enhancedInput->BindAction(MovementAction, ETriggerEvent::Triggered, this, &AFPS_Player::MovementPlayer);
		enhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &AFPS_Player::LookPlayer);
		enhancedInput->BindAction(WeaponChangeAction, ETriggerEvent::Started, this, &AFPS_Player::SelectWeapon);
		
		enhancedInput->BindAction(JumpAction, ETriggerEvent::Started, this, &AFPS_Player::JumpPlayer);
		enhancedInput->BindAction(JumpAction, ETriggerEvent::Completed, this, &AFPS_Player::JumpPlayer);
		
		enhancedInput->BindAction(SprintAction, ETriggerEvent::Started, this, &AFPS_Player::Sprint);
		enhancedInput->BindAction(SprintAction, ETriggerEvent::Completed, this, &AFPS_Player::Sprint);

		enhancedInput->BindAction(CrouchAction, ETriggerEvent::Started, this, &AFPS_Player::CrouchPlayer);
		enhancedInput->BindAction(CrouchAction, ETriggerEvent::Completed, this, &AFPS_Player::CrouchPlayer);


	}



}

void AFPS_Player::OnStartCrouch(float halfHeightAdjust, float scaledHalfHeightAdjust)
{
	if (halfHeightAdjust == 0.0f)
	{
		return;
	}

	float startBaseEyeHeight = BaseEyeHeight;
	Super::OnStartCrouch(halfHeightAdjust, scaledHalfHeightAdjust);
	crouchEyeOffSet.Z += startBaseEyeHeight - BaseEyeHeight + halfHeightAdjust;
	CameraFPS->SetRelativeLocation(FVector(0.0f, 0.0f, BaseEyeHeight));

}

void AFPS_Player::OnEndCrouch(float halfHeightAdjust, float scaledHalfHeightAdjust)
{
	if (halfHeightAdjust == 0.0f)
	{
		return;

	}

	float startBaseEyeHeight = BaseEyeHeight;
	Super::OnEndCrouch(halfHeightAdjust, scaledHalfHeightAdjust);
	crouchEyeOffSet.Z += startBaseEyeHeight - BaseEyeHeight - halfHeightAdjust;
	CameraFPS->SetRelativeLocation(FVector(0.0f, 0.0f, BaseEyeHeight), false);
}

void AFPS_Player::CalcCamera(float DeltaTime, FMinimalViewInfo& OutResult)
{
	if (CameraFPS)
	{
		CameraFPS->GetCameraView(DeltaTime, OutResult);
		OutResult.Location += crouchEyeOffSet;
	}

}



void AFPS_Player::MovementPlayer(const FInputActionValue& valueInput)
{
	FVector2D movementVector = valueInput.Get<FVector2D>();

	//printf("%s", *movementVector.ToString());

	AddMovementInput(GetActorForwardVector(), movementVector.Y);
	AddMovementInput(GetActorRightVector(), movementVector.X);

}

void AFPS_Player::LookPlayer(const FInputActionValue& valueInput)
{
	if (GetController() == nullptr)
	{
		return;
	}

	FVector2D axisVector = valueInput.Get<FVector2D>() * lookSensibility * GetWorld()->GetDeltaSeconds();

	AddControllerPitchInput(axisVector.Y);
	AddControllerYawInput(axisVector.X);
	
	
}

void AFPS_Player::JumpPlayer(const FInputActionValue& valueInput)
{
	if (!isJumping)
	{
		Jump();
	}
	else
	{
		StopJumping();
	}
	isJumping = !isJumping;
}

void AFPS_Player::Sprint(const FInputActionValue& valueInput)
{
	isSprint = !isSprint;

	GetCharacterMovement()->MaxWalkSpeed = (isSprint) ? sprintSpeed : normalSpeed;

}

void AFPS_Player::CrouchPlayer(const FInputActionValue& valueInput)
{
	
	
	if (!isCrouched)
	{
		Crouch();
	}
	else
	{
		UnCrouch();
	}

	isCrouched = !isCrouched;
}



void AFPS_Player::SelectWeapon(const FInputActionValue& valueInput)
{
	
	int idxWeapon = 0;

	TArray<FKey> listKeyAction = Cast<AFPS_Controller>(GetController())->subsystemController->QueryKeysMappedToAction(WeaponChangeAction);
	
	
	for (FKey eachKey : listKeyAction)
	{
		if (Cast<AFPS_Controller>(GetController())->IsInputKeyDown(eachKey))
		{
			idxWeapon = listKeyAction.Find(eachKey);
		}
		
	}
	

	if (weaponComponentPlayer != nullptr)
	{

		auto newWeapon = weaponComponentPlayer->listWeapons[idxWeapon];
		
		
		if (!IsValid(weaponComponentPlayer->GetCurrentWeapon()) || newWeapon == nullptr)
		{
			return;
		}

		

		if (newWeapon != weaponComponentPlayer->GetCurrentWeapon()->GetClass())
		{
			weaponComponentPlayer->ChangeWeapon(newWeapon);
		}
		
	}

}


UWeaponComponent* AFPS_Player::GetWeaponComponentPlayer()
{
	return weaponComponentPlayer;
}

