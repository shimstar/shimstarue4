// Fill out your copyright notice in the Description page of Project Settings.

#include "pocshim.h"
#include "ShimObjectif.h"

ShimObjectif::ShimObjectif()
{
	evt = nullptr;
	actualNbShip = 0;
	status = 0;
}

void ShimObjectif::setTemplate(ShimObjectifTemplate *pTemplate) {
	templateObjectif = pTemplate;
	evt = new ShimEvents();
	evt->setTemplate(templateObjectif->getEventTemplate());
}

void ShimObjectif::UpdateObjectif(int ship) {
	actualNbShip += ship;
	if (templateObjectif != nullptr){
		if (actualNbShip >= templateObjectif->getNbShip()) {
			status = 1;
		}
	}
}

FString ShimObjectif::getObjectif() {
	FString result = "";
	if (templateObjectif != nullptr) {
		result = templateObjectif->getName() + " : " + FString::FromInt(actualNbShip) + " / " + FString::FromInt(templateObjectif->getNbShip());
	}
	return result;
}

ShimObjectif::~ShimObjectif()
{
}
