// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ShimMissionTemplate.h"
#include "ShimObjectifTemplate.h"
#include "ShimObjectif.h"
#include "ShimEvents.h"

/**
 * 
 */
class POCSHIM_API ShimMission
{
	FString id;
	FString name;
	FString text;
	int status; //0 WIP, 1 Finished
	ShimObjectif *objectif;
	ShimMissionTemplate* missionTemplate;
	std::vector<ShimObjectif *> listOfObjectif;
public:
	FString getName() ;
	FString getText() ;
	int getStatus() { return status; };
	int getIdTemplate();
	void setStatus(int pstatus) { status = pstatus; };
	void setId(FString pid) { id = pid; };
	FString getObjectifText();
	void setTemplate(int);
	void updateObjectif(int ship);
	ShimMission();
	~ShimMission();
	std::vector<ShimObjectif*> getObjectifs() { return listOfObjectif; };

};
