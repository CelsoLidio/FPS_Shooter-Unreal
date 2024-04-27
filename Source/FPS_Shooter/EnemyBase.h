// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Perception/AIPerceptionComponent.h"
#include "EnemyAI_Interface.h"

#include "EnemyBase.generated.h"



UCLASS(Blueprintable)
class FPS_SHOOTER_API AEnemyBase : public ACharacter, public IEnemyAI_Interface
{
	GENERATED_BODY()



public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Enemy Defaults")
	float maxHealth;

	UPROPERTY(BlueprintReadWrite, Category = "Enemy Properties")
	float currentHealth;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy AI")
	AActor* patrolRoute;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	UAnimMontage* animTakeDamage;

public:
	// Sets default values for this pawn's properties
	AEnemyBase();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float damageAmount, struct FDamageEvent const& damageEvent, AController* eventInstigator, AActor* damageCauser) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Animation")
	void OnDying();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Animation")
	void OnDamage(AController* damageCauser);

};
