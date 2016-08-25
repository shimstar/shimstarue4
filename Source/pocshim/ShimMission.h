// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ShimMissionTemplate.h"
#include "ShimObjectif.h"

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
public:
	FString getName() { return name; };
	FString getText() { return text; };
	int getStatus() { return status; };
	int getIdTemplate();
	void setStatus(int pstatus) { status = pstatus; };
	void setId(FString pid) { id = pid; };
	FString getObjectifText();
	void setTemplate(int);
	void updateObjectif(int ship);
	ShimMission();
	~ShimMission();

};
