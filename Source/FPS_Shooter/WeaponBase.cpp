// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBase.h"
#include "PrintStrings.h"

UWeaponBase::UWeaponBase()
{
	fireRate = 0.5f;
	reloadingTime = 1.2f;
	maxCountBullet = 10;
	socketSpawnPoint = "socketSpawnBullet";

}