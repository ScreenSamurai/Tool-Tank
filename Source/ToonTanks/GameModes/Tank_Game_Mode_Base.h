// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Tank_Game_Mode_Base.generated.h"

class APawn_Turret;
class APawn_Tank;
class APlayer_Controller_Base;
UCLASS()
class TOONTANKS_API ATank_Game_Mode_Base : public AGameModeBase
{
	GENERATED_BODY()

private:
	APawn_Tank* Player_Tank;
	int32 Target_Turrer = 0;
	APlayer_Controller_Base* Player_Controller_Ref;

	int32 Get_Target_Turret_Count();
	void Handl_Game_Start();
	void Handl_Game_Over(bool PlayerWon);

public:

	void Actor_Dead(AActor* DeadActor);


protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Loop")
	int32 StartDelay = 3;


	virtual void BeginPlay() override;
	UFUNCTION(BlueprintImplementableEvent)
	void GameStart();
	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool PlayerWon);

};
