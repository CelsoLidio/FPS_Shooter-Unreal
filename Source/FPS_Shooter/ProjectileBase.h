// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Components/BoxComponent.h"



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

	UPROPERTY(EditAnywhere, Category = "Collision")
	UBoxComponent* CollisionBox;
	
public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Default Projectile")
	float projectileSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default Projectile")
	float valueDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default Projectile")
	TSubclassOf<UDamageType> damageType;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};
