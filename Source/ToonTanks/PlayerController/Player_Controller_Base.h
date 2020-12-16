// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Player_Controller_Base.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API APlayer_Controller_Base : public APlayerController
{
	GENERATED_BODY()

public:
	void Set_Player_Enabled_State(bool SetPlayerEnabled);
};
