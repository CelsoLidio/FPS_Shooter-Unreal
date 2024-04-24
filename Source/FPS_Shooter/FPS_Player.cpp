// Fill out your copyright notice in the Description page of Project Settings.


#include "FPS_Player.h"
#include "FPS_Controller.h"

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
}

// Called when the game starts or when spawned
void AFPS_Player::BeginPlay()
{
	Super::BeginPlay();


	TArray<USceneComponent*> allChildCamera;

	CameraFPS->GetChildrenComponents(false, allChildCamera);

}

// Called every frame
void AFPS_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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

