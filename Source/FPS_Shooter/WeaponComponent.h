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
UCLASS(Blueprintable,ClassGroup=(Custom), meta = (BlueprintSpawnableComponent))
class FPS_SHOOTER_API UWeaponComponent : public USkeletalMeshComponent
{
	GENERATED_BODY()


private:

	//Weapon Variables//
	UWeaponBase* currentWeapon;
	FTimerHandle handleChangingWeapon;

	//Shooting Variables//
	float clockTimerShooting;
	
	
	//Realoading Variables//
	FTimerHandle handleReload;
	bool isReloading;


public:

	//Weapon Variables//
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	bool isChangingWeapon;
	


public:

	UWeaponComponent();

	//Fire Action//
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	class UInputAction* ShootingAction;

	//Reloding Action//
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	class UInputAction* ReloadAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	TArray<TSubclassOf<UWeaponBase>> listWeapons;


private:

	//Shooting Methods//
	void Shooting();
	void Fire();
	void Reloading();
	void StopReloading();

	//Weapon Methods//
	void DrawWeapon();


protected:

	virtual void BeginPlay() override;

	

public:

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//Weapon Methods Public BP//
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void ChangeWeapon(TSubclassOf<UWeaponBase> newWeapon);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	UWeaponBase* GetCurrentWeapon();
};
