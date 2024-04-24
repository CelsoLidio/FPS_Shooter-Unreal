// Fill out your copyright notice in the Description page of Project Settings.


#include "FPS_Controller.h"

void AFPS_Controller::BeginPlay()
{
	Super::BeginPlay();

	
	if (UEnhancedInputLocalPlayerSubsystem* playerSubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		subsystemController = playerSubSystem;
		playerSubSystem->AddMappingContext(PlayerMappingInput, 0);
		
	}
	

}
