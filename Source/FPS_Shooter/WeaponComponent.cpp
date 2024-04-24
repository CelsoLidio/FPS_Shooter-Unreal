// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponComponent.h"
#include "EnhancedInputComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "PrintStrings.h"

UWeaponComponent::UWeaponComponent()
{
	isReloading = false;

	SetRelativeLocationAndRotation(FVector(50.0f, 0.0f, -160.0f), FRotator(0.0f, -90.0f,0.0f));
}

void UWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	auto* playerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	
	if (playerController != nullptr)
	{
		if (UEnhancedInputComponent* enhancedInput = CastChecked<UEnhancedInputComponent>(playerController->InputComponent))
		{
			enhancedInput->BindAction(ShootingAction, ETriggerEvent::Triggered, this, &UWeaponComponent::Shooting);

		}
	}
	
	if (!listWeapons.IsEmpty())
	{
		ChangeWeapon(listWeapons[0]);
	}


}

void UWeaponComponent::ChangeWeapon(TSubclassOf<UWeaponBase> newWeapon)
{
	currentWeapon = newWeapon.GetDefaultObject();
	

	if (!IsValid(currentWeapon))
	{
		print("[ERROR - ChangeWeapon] New Weapon Invaliid...");
		return;
	}

	if (IsValid(currentWeapon->weaponMesh))
	{
		SetSkeletalMeshAsset(currentWeapon->weaponMesh);
	}
	if (IsValid(currentWeapon->weaponAnimBP))
	{
		SetAnimInstanceClass(currentWeapon->weaponAnimBP->GetAnimBlueprintGeneratedClass());
	}
	
	clockTimerShooting = currentWeapon->fireRate;
	currCountBullet = currentWeapon->countBullet;

	printf("weapon name = %s", *currentWeapon->weaponMesh->GetName());

}

void UWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	clockTimerShooting -= DeltaTime;
}

void UWeaponComponent::Shooting()
{

	if (!IsValid(currentWeapon) || isReloading)
	{
		return;
	}

	
	if (currCountBullet <= 0)
	{
		Reloading();
		
		return;
	}

	if (clockTimerShooting <= 0)
	{
		Fire();

		clockTimerShooting = currentWeapon->fireRate;
	}
	
}

void UWeaponComponent::Fire()
{
	
	
	if (IsValid(currentWeapon->weaponProjectile) && currentWeapon->socketSpawnPoint != "")
	{
		print("FIRE!!");

		GetWorld()->SpawnActor<AProjectileBase>(currentWeapon->weaponProjectile, GetSocketLocation(*currentWeapon->socketSpawnPoint), GetSocketRotation(*currentWeapon->socketSpawnPoint));

		currCountBullet -= 1;
	}

	
}

void UWeaponComponent::Reloading()
{
	if (!IsValid(currentWeapon)) 
	{
		return;
	}

	if (!GetWorld()->GetTimerManager().IsTimerActive(handleReload))
	{
		isReloading = true;		
		GetWorld()->GetTimerManager().SetTimer(handleReload, this, &UWeaponComponent::Reloading, currentWeapon->reloadingTime);
		print("Reloading!!");
	}
	else
	{
		currCountBullet = currentWeapon->countBullet;
		isReloading = false;
		print("AFTER RELOADING");
		GetWorld()->GetTimerManager().ClearTimer(handleReload);

	}


	
	

}


