// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBase.h"
#include "PrintStrings.h"

UWeaponBase::UWeaponBase()
{
	fireRate = 0.5f;
	drawWeaponTime = 1.0f;
	maxCountBullet = 10;
	socketSpawnPoint = "socketSpawnBullet";

}