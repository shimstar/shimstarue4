// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ShimEventsTemplate.h"

/**
 * 
 */
class POCSHIM_API ShimObjectifTemplate
{
	int id;
	FString name;
	int nbShip;
	int typeObjectif;
	int status;
	ShimEventsTemplate *evt;
public:
	FString getName() { return name; };
	int getNbShip() { return nbShip; };
	ShimObjectifTemplate();
	~ShimObjectifTemplate();
	void loadObjectif(TSharedPtr<FJsonObject>);
	ShimEventsTemplate *getEventTemplate() { return evt; };
};
