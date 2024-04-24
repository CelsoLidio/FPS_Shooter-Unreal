// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ProjectileBase.generated.h"

UCLASS()
class FPS_SHOOTER_API AProjectileBase : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AProjectileBase();

protected:

	UPROPERTY(EditAnywhere, Category = "root")
	USceneComponent* rootComp;

	UPROPERTY(EditAnywhere, Category = "Projectile")
	UStaticMeshComponent* projectileMesh;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Projectile")
	UProjectileMovementComponent* projectileMovement;


public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Default Projectile")
	float projectileSpeed;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
