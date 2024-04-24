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
			enhancedInput->BindAction(ReloadAction, ETriggerEvent::Started, this, &UWeaponComponent::Reloading);
		}
	}
	
	if (!listWeapons.IsEmpty())
	{
		for (TSubclassOf<UWeaponBase> eachWeapon : listWeapons)
		{
			eachWeapon.GetDefaultObject()->countBullet = eachWeapon.GetDefaultObject()->maxCountBullet;
		}

		ChangeWeapon(listWeapons[0]);
	}


}

void UWeaponComponent::ChangeWeapon(TSubclassOf<UWeaponBase> newWeapon)
{
	
	
	if (!IsValid(newWeapon.GetDefaultObject()))
	{
		print("[ERROR - ChangeWeapon] New Weapon Invaliid...");
		return;
	}

	currentWeapon = newWeapon.GetDefaultObject();

	if (IsValid(currentWeapon->weaponMesh))
	{
		SetSkeletalMeshAsset(currentWeapon->weaponMesh);
	}
	if (IsValid(currentWeapon->weaponAnimBP))
	{
		SetAnimInstanceClass(currentWeapon->weaponAnimBP->GetAnimBlueprintGeneratedClass());
	}
	
	clockTimerShooting = currentWeapon->fireRate;
	
	if (isReloading)
	{
		StopReloading();
	}

	printf("weapon name = %s", *currentWeapon->weaponMesh->GetName());

}

UWeaponBase* UWeaponComponent::GetCurrentWeapon()
{
	return currentWeapon;
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

	
	if (currentWeapon->countBullet <= 0)
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

		if (GetAnimInstance() != nullptr && currentWeapon->animShooting != nullptr)
		{
			GetAnimInstance()->Montage_Play(currentWeapon->animShooting, 0.7f);
		}

		GetWorld()->SpawnActor<AProjectileBase>(currentWeapon->weaponProjectile, GetSocketLocation(*currentWeapon->socketSpawnPoint), GetSocketRotation(*currentWeapon->socketSpawnPoint));

		currentWeapon->countBullet -= 1;
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
		if (currentWeapon->countBullet >= currentWeapon->maxCountBullet)
		{
			return;
		}

		isReloading = true;		
		GetWorld()->GetTimerManager().SetTimer(handleReload, this, &UWeaponComponent::Reloading, currentWeapon->animReload->GetSectionLength(0));
		
		if (GetAnimInstance() != nullptr && currentWeapon->animReload != nullptr)
		{
			GetAnimInstance()->Montage_Play(currentWeapon->animReload, 1.0f);
		}
	}
	else
	{
		if (GetWorld()->GetTimerManager().GetTimerRemaining(handleReload) <= 0)
		{
			currentWeapon->countBullet = currentWeapon->maxCountBullet;
			StopReloading();
			print("AFTER RELOADING!");
		}
	}


	
	

}

void UWeaponComponent::StopReloading()
{
	isReloading = false;
	GetWorld()->GetTimerManager().ClearTimer(handleReload);
}


