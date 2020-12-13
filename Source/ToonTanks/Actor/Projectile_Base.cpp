// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile_Base.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AProjectile_Base::AProjectile_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Projectile_Mash = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mash"));
	RootComponent = Projectile_Mash;
	Projectile_Movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	Projectile_Movement->InitialSpeed = Movement_Speed;
	Projectile_Movement->MaxSpeed = Movement_Speed;
	InitialLifeSpan = 3.0f;
}

// Called when the game starts or when spawned
void AProjectile_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
//void AProjectile_Base::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

