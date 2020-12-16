// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank_Game_Mode_Base.h"
#include "ToonTanks/Pawns/Pawn_Turret.h"
#include "ToonTanks/Pawns/Pawn_Tank.h"
#include "ToonTanks/PlayerController/Player_Controller_Base.h"
#include "Kismet/GameplayStatics.h"

void ATank_Game_Mode_Base::BeginPlay()
{
	Super::BeginPlay();

	Handl_Game_Start();
}


void ATank_Game_Mode_Base::Handl_Game_Start()
{
	Target_Turrer = Get_Target_Turret_Count();

	Player_Tank = Cast<APawn_Tank>(UGameplayStatics::GetPlayerPawn(this,0));

	Player_Controller_Ref = Cast<APlayer_Controller_Base>(UGameplayStatics::GetPlayerController(this, 0));

	if (Player_Controller_Ref)
	{
		Player_Controller_Ref->Set_Player_Enabled_State(false);

		FTimerHandle Player_Enable_Handle;
		FTimerDelegate Player_Enable_Delegat = FTimerDelegate::CreateUObject(Player_Controller_Ref, &APlayer_Controller_Base::Set_Player_Enabled_State,true);
		GetWorld()->GetTimerManager().SetTimer(Player_Enable_Handle,Player_Enable_Delegat,StartDelay,false);
	}

	GameStart();
}

void ATank_Game_Mode_Base::Handl_Game_Over(bool PlayerWon)
{
	GameOver(PlayerWon);
}

void ATank_Game_Mode_Base::Actor_Dead(AActor* DeadActor)
{
	if (DeadActor == Player_Tank)
	{
		Player_Tank->HandleDistruction();
		Handl_Game_Over(false);

		if (Player_Controller_Ref)
		{
			Player_Controller_Ref->Set_Player_Enabled_State(false);
		}
	}
	else if (APawn_Turret* Destroyed_Turret=Cast<APawn_Turret>(DeadActor))
	{
		Destroyed_Turret->HandleDistruction();

		if (--Target_Turrer == 0)
		{
			Handl_Game_Over(true);
		}
	}
}

int32 ATank_Game_Mode_Base::Get_Target_Turret_Count()
{
	TArray<AActor*> Turret_Actor;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APawn_Turret::StaticClass(),Turret_Actor);
	return Turret_Actor.Num();
}
