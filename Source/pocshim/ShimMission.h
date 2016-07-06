// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ShimObjectif.h"
/**
 * 
 */
class POCSHIM_API ShimMission
{
	int id;
	FString name;
	FString text;
	int status; //0 WIP, 1 Finished
	ShimObjectif *objectif;
public:
	FString getName() { return name; };
	FString getText() { return text; };
	int getStatus() { return status; };
	FString getObjectifText();
	ShimMission();
	~ShimMission();
};
