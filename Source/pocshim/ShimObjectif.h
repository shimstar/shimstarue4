// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ShimObjectifTemplate.h"
#include "ShimEvents.h"
/**
 * 
 */
class POCSHIM_API ShimObjectif
{
private:
	int actualNbShip;
	int status;
	ShimEvents *evt;
	ShimObjectifTemplate *templateObjectif;
public:
	FString getObjectif();
	void setTemplate(ShimObjectifTemplate*);
	void UpdateObjectif(int ship);
	int getStatus() { return status; };
	ShimEvents *getEvents() { return evt; };
	ShimObjectif();
	~ShimObjectif();
};
