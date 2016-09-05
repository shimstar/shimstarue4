// Fill out your copyright notice in the Description page of Project Settings.

#include "pocshim.h"
#include "DarkFIghterClass.h"


// Sets default values
ADarkFIghterClass::ADarkFIghterClass()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


// Called when the game starts or when spawned
void ADarkFIghterClass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADarkFIghterClass::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

// Called to bind functionality to input
void ADarkFIghterClass::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

float ADarkFIghterClass::GetHealth() {
	return 0.0f;
}

