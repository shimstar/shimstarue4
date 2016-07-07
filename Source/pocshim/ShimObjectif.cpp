// Fill out your copyright notice in the Description page of Project Settings.

#include "pocshim.h"
#include "ShimObjectif.h"

ShimObjectif::ShimObjectif()
{
	id = 1;
	name = "Petit pirate";
	nbShip = 1;
	actualNbShip = 0;
	status = 0;
	typeObjectif = 1;
}

void ShimObjectif::UpdateObjectif(int ship) {
	actualNbShip += ship;
	if (actualNbShip >= nbShip) {
		status = 1;
	}
}

FString ShimObjectif::getObjectif() {
	FString result = name + " : " + FString::FromInt(actualNbShip) + " / "  + FString::FromInt(nbShip);
	return result;
}

ShimObjectif::~ShimObjectif()
{
}
