// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileBase.h"

// Sets default values
AProjectileBase::AProjectileBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	//Create Objects//
	rootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	rootComp->SetupAttachment(RootComponent);

	projectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
	projectileMesh->SetupAttachment(rootComp);
	projectileMesh->SetRelativeRotation(FRotator(0.0f, 0.0f, -90.0f));


	projectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	

	//Default Variables//
	projectileSpeed = 6000.0f;
	projectileMovement->ProjectileGravityScale = 0.0f;
	projectileMovement->InitialSpeed = projectileSpeed;
	projectileMovement->MaxSpeed = projectileSpeed;
	SetLifeSpan(2.0f);

}

// Called when the game starts or when spawned
void AProjectileBase::BeginPlay()
{
	Super::BeginPlay();
	
	projectileMovement->InitialSpeed = projectileSpeed;
	projectileMovement->MaxSpeed = projectileSpeed;
}

// Called every frame
void AProjectileBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

