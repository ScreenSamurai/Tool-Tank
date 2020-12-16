// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Base_Pawn.h"
#include "Pawn_Turret.generated.h"

class APawn_Tank;

UCLASS()
class TOONTANKS_API APawn_Turret : public ABase_Pawn
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Combat", meta=(AllowPrivateAccess="true"))
	float Fire_Rate = 2.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float Fire_Range = 500.f;

	FTimerHandle Fire_Rate_Timer_Handle;
	APawn_Tank* Player_Pawn;

	void Check_Fire_Condition();

	float Return_Distance_To_Player();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void HandleDistruction() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
