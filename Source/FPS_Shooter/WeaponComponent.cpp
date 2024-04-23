// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponComponent.h"
#include "EnhancedInputComponent.h"
#include "PrintStrings.h"

UWeaponComponent::UWeaponComponent()
{
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
	UWeaponBase* currWeapon = newWeapon.GetDefaultObject();
	

	if (currWeapon == nullptr)
	{
		print("[ERROR - ChangeWeapon] New Weapon Invaliid...");
		return;
	}

	SetSkeletalMeshAsset(currWeapon->weaponMesh);
	printf("weapon name = %s", *currWeapon->weaponMesh->GetName());

}

void UWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UWeaponComponent::Shooting()
{
	print("FIRE!!")
}
