// Fill out your copyright notice in the Description page of Project Settings.


#include "FPS_Player.h"

// Sets default values
AFPS_Player::AFPS_Player()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Criando Camera FPS
	CameraFPS = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraFPS"));
	CameraFPS->SetupAttachment(GetCapsuleComponent());
	CameraFPS->bUsePawnControlRotation = true;


	//Criando Mesh para os braços
	HandsMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("HandsMesh"));
	HandsMesh->SetupAttachment(CameraFPS);
	HandsMesh->SetRelativeLocationAndRotation(FVector(-10.0f, 0.0f, -160.0f), FRotator(0.0f, -90.0f,0.0f));

}

// Called when the game starts or when spawned
void AFPS_Player::BeginPlay()
{
	Super::BeginPlay();
	
	//Create Input Mapping
	if (APlayerController* playerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* playerSubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer()))
		{
			playerSubSystem->AddMappingContext(PlayerMappingInput, 0);
		}
	}

	movementVector = FVector2D::ZeroVector;
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
	}



}

void AFPS_Player::MovementPlayer(const FInputActionValue& valueInput)
{

	

	if (movementVector != valueInput.Get<FVector2D>())
	{
		movementVector = valueInput.Get<FVector2D>();
	}

	GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Emerald, "Input movimento = " + movementVector.ToString());

	//printf("%s", movementVector.ToString());

	const FVector forwardDir = GetActorForwardVector();
	AddMovementInput(forwardDir, movementVector.Y);

	const FVector rightDir = GetActorRightVector();
	AddMovementInput(rightDir, movementVector.X);

}

