// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase.h"
#include "Kismet/GameplayStatics.h"

#include "PrintStrings.h"

// Sets default values
AEnemyBase::AEnemyBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -85.0f), FRotator(0.0f, -90.0f, 0.0f));


	maxHealth = 100.0f;
}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	
	currentHealth = maxHealth;
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

// Called to bind functionality to input
void AEnemyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float AEnemyBase::TakeDamage(float damageAmount, FDamageEvent const& damageEvent, AController* eventInstigator, AActor* damageCauser)
{

	currentHealth -= damageAmount;
	GetMesh()->GetAnimInstance()->Montage_Play(animTakeDamage,0.5f);
	OnDamage(eventInstigator);

	if (currentHealth <= 0)
	{
		OnDying();
	}
	
	printf("Current life = %f", currentHealth);

	return damageAmount;
}

void AEnemyBase::OnDamage_Implementation(AController* damageCauser)
{
}

void AEnemyBase::OnDying_Implementation()
{

}
