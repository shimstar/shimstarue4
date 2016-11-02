// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector>
#include <iostream>
#include "Json.h"

/**
 * 
 */
class POCSHIM_API ShimEventsTemplate
{
private:
	static std::vector<ShimEventsTemplate *> listOfEvents;
	FString name;
	FString id;
	int relatedMission;
	int possibility;
	bool reproduceEvenMissionFinished;
	FString spawnArchetype;
	int32 spawnX, spawnY, spawnZ;
	int nbShip;
public:
	ShimEventsTemplate();
	~ShimEventsTemplate();
	static void loadEvents();
	static ShimEventsTemplate *getTemplate(FString id);
	void setInfos(TSharedPtr<FJsonObject>);
};
