// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBase.h"

UWeaponBase::UWeaponBase()
{
	fireRate = 0.5f;
	reloadingTime = 1.2f;
	countBullet = 10;
	socketSpawnPoint = "socketSpawnBullet";

}