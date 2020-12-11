// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn_Turret.h"
#include "Kismet/GameplayStatics.h"
#include "Pawn_Tank.h"

void APawn_Turret::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(Fire_Rate_Timer_Handle, this, &APawn_Turret::Check_Fire_Condition,Fire_Rate,true);

	Player_Pawn = Cast<APawn_Tank>(UGameplayStatics::GetPlayerPawn(this,0));
}


// Called every frame
void APawn_Turret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!Player_Pawn || Return_Distance_To_Player() >Fire_Range)
	{
		return;
	}

	Rotated_Turret(Player_Pawn->GetActorLocation());
}

void APawn_Turret::Check_Fire_Condition()
{
	if (!Player_Pawn)
	{
		return;	
	}
	if (Return_Distance_To_Player() <= Fire_Range)
	{
		Fire();
	}
}

float APawn_Turret::Return_Distance_To_Player()
{
	if (!Player_Pawn)
	{
		return 0.0f;
	}
	float Distance = FVector::Dist(Player_Pawn->GetActorLocation(),GetActorLocation());
	return Distance;
}

void APawn_Turret::HandleDistruction()
{
	Super::HandleDistruction();


}