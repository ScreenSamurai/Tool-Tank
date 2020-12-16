// Fill out your copyright notice in the Description page of Project Settings.


#include "Player_Controller_Base.h"

void APlayer_Controller_Base::Set_Player_Enabled_State(bool SetPlayerEnabled)
{
	if (SetPlayerEnabled)
	{
		GetPawn()->EnableInput(this);
	}
	else
	{
		GetPawn()->DisableInput(this);
	}
	bShowMouseCursor = SetPlayerEnabled;
}