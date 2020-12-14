// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank_Game_Mode_Base.h"

void ATank_Game_Mode_Base::BeginPlay()
{
	Super::BeginPlay();
}

void ATank_Game_Mode_Base::HandlGameStart()
{
}

void ATank_Game_Mode_Base::HandlGameOver(bool PlayerWon)
{
}

void ATank_Game_Mode_Base::Actor_Died(AActor* DeadActor)
{
	UE_LOG(LogTemp, Warning, TEXT("A Pawn Died!"));
}

