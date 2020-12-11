// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn_Turret.h"
#include "Kismet/GameplayStatics.h"

void APawn_Turret::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(Fire_Rate_Timer_Handle, this, &APawn_Turret::CheckFireCondition,Fire_Rate,true);
}

// Called every frame
void APawn_Turret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APawn_Turret::CheckFireCondition()
{
	UE_LOG(LogTemp, Warning, TEXT("Fire Condition Checked"));
}