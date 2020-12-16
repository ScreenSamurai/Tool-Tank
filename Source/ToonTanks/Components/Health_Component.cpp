// Fill out your copyright notice in the Description page of Project Settings.


#include "Health_Component.h"
#include "ToonTanks/GameModes/Tank_Game_Mode_Base.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UHealth_Component::UHealth_Component()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UHealth_Component::BeginPlay()
{
	Super::BeginPlay();

	Health = Default_Health;
	Game_Mode_Ref = Cast<ATank_Game_Mode_Base>(UGameplayStatics::GetGameMode(GetWorld()));
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealth_Component::Take_Damage);
	
}

void UHealth_Component::Take_Damage(AActor* DamageActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage == 0 || Health <=0)
	{
		return;
	}

	Health = FMath::Clamp(Health - Damage,0.0f,Default_Health);

	if (Health <=0)
	{
		if (Game_Mode_Ref)
		{
			Game_Mode_Ref->Actor_Dead(GetOwner());
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Health Component has no reference to the GameMode!"));
		}
	}
}



