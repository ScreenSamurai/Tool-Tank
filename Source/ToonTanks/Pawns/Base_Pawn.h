// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ToonTanks/Actor/Projectile_Base.h"
#include "Base_Pawn.generated.h"

class UCapsuleComponent;

UCLASS()
class TOONTANKS_API ABase_Pawn : public APawn
{
	GENERATED_BODY()

private:
	//Componets
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* BaseMash;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* TurreMash;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		USceneComponent* ProjectileSpawnPoint;
	//Varibles
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Projectile", meta=(AllowPrivateAccess = "True"))
	TSubclassOf<AProjectile_Base> Projectile_Class;

public:
	// Sets default values for this pawn's properties
	ABase_Pawn();

	virtual void HandleDistruction(); 

protected:

	void Rotated_Turret(FVector Look_at_Target);

	void Fire();

};
