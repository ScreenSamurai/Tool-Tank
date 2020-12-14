// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Health_Component.generated.h"

class ATank_Game_Mode_Base;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOONTANKS_API UHealth_Component : public UActorComponent
{
	GENERATED_BODY()

private:


	UPROPERTY(EditAnywhere)
	float Default_Health = 100.0f;
	float Health = 0.0f;

	ATank_Game_Mode_Base* Game_Mode_Ref;

public:	
	// Sets default values for this component's properties
	UHealth_Component();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;	

	UFUNCTION()
	void Take_Damage(AActor* DamageActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);
};
