// Fill out your copyright notice in the Description page of Project Settings.


#include "Base_Pawn.h"
#include "ToonTanks/Actor/Projectile_Base.h"
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

void ABase_Pawn::Rotated_Turret(FVector Look_at_Target)
{

	// Update TurretMesh rotation to face towards the LookAtTarget passed in from Child Classes.
	// TurretMesh->SetWorldRotation()...
	FVector Look_at_Target_Cleaned = FVector(Look_at_Target.X, Look_at_Target.Y, TurreMash->GetComponentLocation().Z);
	FVector Start_Location = TurreMash->GetComponentLocation();

	FRotator Turret_Location = FVector(Look_at_Target_Cleaned - Start_Location).Rotation();
	TurreMash->SetWorldRotation(Turret_Location);
}

void ABase_Pawn::Fire()
{
	// Get ProjectileSpawnPoint Location && Rotation -> Spawn Projectile class at Location firing towards Rotation.
	if (Projectile_Class)
	{
		FVector Spawn_Location = ProjectileSpawnPoint->GetComponentLocation();
		FRotator Spawn_Rotator = ProjectileSpawnPoint->GetComponentRotation();

		AProjectile_Base* TempProjectile = GetWorld()->SpawnActor<AProjectile_Base>(Projectile_Class, Spawn_Location, Spawn_Rotator);
		TempProjectile->SetOwner(this);
	}
}

void ABase_Pawn::HandleDistruction()
{

	// --- Universal functionality --- 
	// Play death effects particle, sound and camera shake. 

	// --- Then do Child overrides ---
	// -- PawnTurret - Inform GameMode Turret died -> Then Destroy() self. 

	// -- PawnTank - Inform GameMode Player died -> Then Hide() all components && stop movement input.


}


