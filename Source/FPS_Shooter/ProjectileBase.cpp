// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileBase.h"
#include "Kismet/GameplayStatics.h"
#include "EnemyBase.h"

#include "PrintStrings.h"


// Sets default values
AProjectileBase::AProjectileBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	//Create Objects//
	rootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	rootComp->SetupAttachment(RootComponent);

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionBox->SetupAttachment(rootComp);

	projectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
	projectileMesh->SetupAttachment(CollisionBox);
	projectileMesh->SetRelativeRotation(FRotator(0.0f, 0.0f, -90.0f));


	projectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));


	//Default Variables//
	projectileSpeed = 6000.0f;
	projectileMovement->ProjectileGravityScale = 0.0f;
	projectileMovement->InitialSpeed = projectileSpeed;
	projectileMovement->MaxSpeed = projectileSpeed;
	SetLifeSpan(2.0f);
	valueDamage = 25.0f;
}

// Called when the game starts or when spawned
void AProjectileBase::BeginPlay()
{
	Super::BeginPlay();
	
	projectileMovement->InitialSpeed = projectileSpeed;
	projectileMovement->MaxSpeed = projectileSpeed;

	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AProjectileBase::OverlapBegin);
	CollisionBox->OnComponentHit.AddDynamic(this, &AProjectileBase::OnHit);
}

// Called every frame
void AProjectileBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AProjectileBase::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != nullptr && OtherActor != this && OtherComp != nullptr)
	{
		

		if (Cast<AEnemyBase>(OtherActor))
		{
			AEnemyBase* myEnemy = Cast<AEnemyBase>(OtherActor);
			AController* pController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
			
			UGameplayStatics::ApplyDamage(myEnemy, valueDamage, pController,this, damageType);
		}

		
		
	}
	Destroy();
	print("OVERLAP");
}


void AProjectileBase::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	Destroy();
	print("HIT DESTROY");
}

