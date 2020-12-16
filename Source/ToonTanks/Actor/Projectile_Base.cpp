// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile_Base.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AProjectile_Base::AProjectile_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Projectile_Mash = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mash"));
	Projectile_Mash->OnComponentHit.AddDynamic(this, &AProjectile_Base::OnHit);
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

void AProjectile_Base::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	// Try to get a reference to the owning class.
	AActor* MyOwner = GetOwner();
	// If for some reason we can't get a valid reference, return as we need to check against the owner. 
	if (!MyOwner)
	{
		return;
	}
	// If the other ISN'T self OR Owner AND exists, then apply damage. 
	if (OtherActor && OtherActor != this && OtherActor != MyOwner)
	//if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComponent != nullptr))
	{
		UGameplayStatics::ApplyDamage(OtherActor, Damage, MyOwner->GetInstigatorController(), this, Damage_Type);
	}
	Destroy();
	// Play a bunch of effects here during the polish phase. - TODO
}


// Called every frame
//void AProjectile_Base::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}


