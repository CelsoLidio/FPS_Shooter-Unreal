// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//#include "UObject/NoExportTypes.h"
#include "ProjectileBase.h"
#include "WeaponBase.generated.h"



/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class FPS_SHOOTER_API UWeaponBase : public UObject
{
	GENERATED_BODY()
	

	UWeaponBase();

public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Mesh")
	USkeletalMesh* weaponMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	UAnimBlueprint* weaponAnimBP;
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	TSubclassOf<AProjectileBase> weaponProjectile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float drawWeaponTime;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shooting Configuration")
	float fireRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shooting Configuration")
	int maxCountBullet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shooting Configuration")
	FString socketSpawnPoint;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	UAnimMontage* animShooting;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	UAnimMontage* animReload;

	
	int countBullet;

};
