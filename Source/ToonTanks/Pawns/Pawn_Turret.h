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
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Combat", meta=(AllowPrivateAccess="true"))
	float Fire_Rate = 2.f;

	void CheckFireCondition();

	FTimerHandle Fire_Rate_Timer_Handle;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
