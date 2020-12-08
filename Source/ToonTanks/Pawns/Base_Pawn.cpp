// Fill out your copyright notice in the Description page of Project Settings.


#include "Base_Pawn.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ABase_Pawn::ABase_Pawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateAbstractDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;

	BaseMash = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mash"));
	BaseMash->SetupAttachment(RootComponent);

	TurreMash = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("TurreMash Mash"));
	TurreMash->SetupAttachment(BaseMash);

	ProjectileSpawnPoint = CreateAbstractDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurreMash);
}


