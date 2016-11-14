// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ShimEventsTemplate.h"

/**
 * 
 */
class POCSHIM_API ShimEvents
{
	ShimEventsTemplate *evtTemplate;
	int nbShipSpawn;
public:
	ShimEvents();
	~ShimEvents();
	void init(TSharedPtr<FJsonObject>);
	void setTemplate(ShimEventsTemplate *);
	ShimEventsTemplate *getTemplate() { return evtTemplate; };
	int getNbShipSpawn() { return nbShipSpawn; };
	void setNbShipSpawn(int32);
};
