// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "WeaponBase.h"
#include "Engine/SkeletalMeshSocket.h"

#include "WeaponComponent.generated.h"



class AProjectileBase;

//class AFPS_Player;
/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta = (BlueprintSpawnableComponent))
class FPS_SHOOTER_API UWeaponComponent : public USkeletalMeshComponent
{
	GENERATED_BODY()


private:

	UWeaponBase* currentWeapon;
	int currCountBullet;
	float clockTimerShooting;
	
	//Reloading Weapon//
	bool isReloading;
	FTimerHandle handleReload;


public:

	UWeaponComponent();

	//Fire Action//
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	class UInputAction* ShootingAction;


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Adjust Weapons")
	TArray<TSubclassOf<UWeaponBase>> listWeapons;


private:

	void Shooting();
	void Fire();
	void Reloading();

protected:

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Adjust Weapons")
	void ChangeWeapon(TSubclassOf<UWeaponBase> newWeapon);

public:

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};
