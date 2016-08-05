// Fill out your copyright notice in the Description page of Project Settings.

#include "pocshim.h"
#include "Blueprint/UserWidget.h"
#include "ShimPlayerControllerMenu.h"



void AShimPlayerControllerMenu::showListOfMission(std::vector<ShimMissionTemplate *> stationMissions) {
	for (int i = 0; i < stationMissions.size(); i++) {
		if (stationMissionWidgetBP) {
			Utinymissionwidgetclass *stationMissionWidget = CreateWidget<Utinymissionwidgetclass>(this, stationMissionWidgetBP);
			stationMissionWidget->SetPositionInViewport(FVector2D(300, 70 + 120*i));
			stationMissionWidget->faceValue = stationMissions[i]->getfaceNpc();
			stationMissionWidget->location = stationMissions[i]->getLocation();
			stationMissionWidget->summary = stationMissions[i]->getName();
			stationMissionWidget->id = stationMissions[i]->getId();
			stationMissionWidget->AddToViewport();
			
		}
	}
}

void AShimPlayerControllerMenu::showMission(ShimMissionTemplate *mission) {
	if (oneMissionWidgetBP) {
		UOneMissionWidgetClass *oneMissionWidget = CreateWidget<UOneMissionWidgetClass>(this, oneMissionWidgetBP);
		oneMissionWidget->faceValue = mission->getfaceNpc();
		oneMissionWidget->faceNameValue = mission->getNameNpc();
		oneMissionWidget->summary = mission->getName();
		oneMissionWidget->text = mission->getNewText();
		oneMissionWidget->AddToViewport();
	}
}