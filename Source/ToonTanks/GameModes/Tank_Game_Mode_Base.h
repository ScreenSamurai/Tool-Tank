// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Tank_Game_Mode_Base.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank_Game_Mode_Base : public AGameModeBase
{
	GENERATED_BODY()

private:

	void HandlGameStart();
	void HandlGameOver(bool PlayerWon);


public:

	void Actor_Died(AActor* DeadActor);

protected:
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintImplementableEvent)
	void GameStart();
	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool PlayerWon);

};
