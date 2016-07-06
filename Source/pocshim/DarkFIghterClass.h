// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "ShimServer.h"
#include "InterfaceShip.h"
#include "DarkFIghterClass.generated.h"


UCLASS()
class POCSHIM_API ADarkFIghterClass : public APawn, public IInterfaceShip
{
	GENERATED_BODY()
private:
	float hullPoints;
	float maxHullPoints;

public:
	// Sets default values for this pawn's properties
	ADarkFIghterClass();
	

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	virtual float GetHealth() override;
};
