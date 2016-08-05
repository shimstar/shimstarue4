// Fill out your copyright notice in the Description page of Project Settings.

#include "pocshim.h"
#include "UserWidgetMissionClass.h"


void UUserWidgetMissionClass::DrawMissionToBP(ShimMission *mission) {
	if(mission){
		MissionName = FText::FromString(mission->getName());
		MissionStatus = mission->getStatus();
		MissionText = FText::FromString(mission->getText());
		ObjectifText = FText::FromString(mission->getObjectifText());
		this->DrawMission();
		this->DrawMissionText();
	}
}

