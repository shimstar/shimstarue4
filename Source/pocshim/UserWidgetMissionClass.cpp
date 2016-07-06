// Fill out your copyright notice in the Description page of Project Settings.

#include "pocshim.h"
#include "UserWidgetMissionClass.h"


void UUserWidgetMissionClass::DrawMissionToBP(FString pMissionName, int pMissionStatus) {
	MissionName = FText::FromString(pMissionName);
	MissionStatus = pMissionStatus;
	this->DrawMission();
}

