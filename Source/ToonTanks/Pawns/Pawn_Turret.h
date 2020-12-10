// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Base_Pawn.h"
#include "Pawn_Turret.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API APawn_Turret : public ABase_Pawn
{
	GENERATED_BODY()

private:

	void CheckFireCondition();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	FTimerHandle Fire_Rate_Timer_Handle;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
