// Fill out your copyright notice in the Description page of Project Settings.

#include "pocshim.h"
#include "Blueprint/UserWidget.h"
#include "ShimPlayerControllerMenu.h"



void AShimPlayerControllerMenu::showListOfMission(std::vector<ShimMissionTemplate *> stationMissions) {
	for (int i = 0; i < stationMissions.size(); i++) {
		if (stationMissionWidgetBP) {
			stationMissionWidget = CreateWidget<Utinymissionwidgetclass>(this, stationMissionWidgetBP);
			stationMissionWidget->SetPositionInViewport(FVector2D(300, 70 + 120*i));
			stationMissionWidget->faceValue = stationMissions[i]->getfaceNpc();
			stationMissionWidget->AddToViewport();

		}
		else {
			GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, TEXT("template nukl"));
		}
	}
}
