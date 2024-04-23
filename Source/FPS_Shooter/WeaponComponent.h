// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "WeaponBase.h"
#include "WeaponComponent.generated.h"


//class AFPS_Player;
/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta = (BlueprintSpawnableComponent))
class FPS_SHOOTER_API UWeaponComponent : public USkeletalMeshComponent
{
	GENERATED_BODY()
	
public:

	UWeaponComponent();

	//Fire Action//
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Input")
	class UInputAction* ShootingAction;


	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Adjust Weapons")
	TArray<TSubclassOf<UWeaponBase>> listWeapons;



protected:

	virtual void BeginPlay() override;

	void ChangeWeapon(TSubclassOf<UWeaponBase> newWeapon);

public:

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	void Shooting();


};
