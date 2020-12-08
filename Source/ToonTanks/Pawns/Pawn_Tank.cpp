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

}

// Called every frame
void APawn_Tank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APawn_Tank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}