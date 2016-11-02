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
};
