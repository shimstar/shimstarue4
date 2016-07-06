// Fill out your copyright notice in the Description page of Project Settings.

#include "pocshim.h"
#include "InterfaceShip.h"

UInterfaceShip::UInterfaceShip(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

float IInterfaceShip::GetHealth() {
	return 0.0f;
}