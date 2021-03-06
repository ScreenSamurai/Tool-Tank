// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn_Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

APawn_Tank::APawn_Tank()
{
	/*Spring_Arm = CreateAbstractDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	Spring_Arm->SetupAttachment(RootComponent);*/
	Spring_Arm = CreateAbstractDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	Spring_Arm->SetupAttachment(RootComponent);
	Camera = CreateAbstractDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(Spring_Arm);
}

// Called when the game starts or when spawned
void APawn_Tank::BeginPlay()
{
	Super::BeginPlay();

	Player_Controller_Refl = Cast<APlayerController>(GetController());
}


// Called every frame
void APawn_Tank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Rotate();
	Move();

	if (Player_Controller_Refl)
	{
		FHitResult Trace_Hit_Result;
		Player_Controller_Refl->GetHitResultUnderCursor(ECC_Visibility,false,Trace_Hit_Result);
		FVector HitLocation = Trace_Hit_Result.ImpactPoint;

		Rotated_Turret(HitLocation);
	}
}

// Called to bind functionality to input
void APawn_Tank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &APawn_Tank::Calculate_Move_Input);
	PlayerInputComponent->BindAxis("Turn", this, &APawn_Tank::Calculate_Rotate_Input);
	PlayerInputComponent->BindAction("Fire",IE_Pressed,this, &APawn_Tank::Fire);

	/*PlayerInputComponent->BindAction("Crouch",IE_Pressed,this, &APawn_Tank::BeginCrouch );
	PlayerInputComponent->BindAction("Crouch", IE_Released,this, &APawn_Tank::LeaveCrouch );*/
}


void APawn_Tank::Calculate_Move_Input(float Value)
{
	Move_Direction = FVector(Value*Move_Speed*GetWorld()->DeltaTimeSeconds,0,0);
}

void APawn_Tank::Calculate_Rotate_Input(float Value)
{
	float RotateAmount = Value * Rotate_Speed * GetWorld()->DeltaTimeSeconds;
	FRotator Rotation = FRotator (0, RotateAmount, 0);
	Rotetion_Derection = FQuat(Rotation);

}

void APawn_Tank::Move()
{
	AddActorLocalOffset(Move_Direction, true);
}

void APawn_Tank::Rotate()
{
	AddActorLocalRotation(Rotetion_Derection,true);
}

void APawn_Tank::HandleDistruction()
{
	Super::HandleDistruction();
	//Destroy();

}