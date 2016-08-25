// Fill out your copyright notice in the Description page of Project Settings.

#include "pocshim.h"
#include "Blueprint/UserWidget.h"
#include "ShimPlayerControllerMenu.h"



void AShimPlayerControllerMenu::showListOfMission(std::vector<ShimMissionTemplate *> stationMissions) {
	ShimPlayer *currentPlayer = ShimPlayer::getInstance();
	std::vector<ShimMission *> listOfMission = currentPlayer->getListOfMission();
	int currentCount = 0;
	for (int i = 0; i < stationMissions.size(); i++) {
		bool found = false;
		for (int itPlayerMission = 0; itPlayerMission < listOfMission.size(); itPlayerMission++) {
			UE_LOG(ShimLog, Warning, TEXT("Mission player %d"), listOfMission[itPlayerMission]->getIdTemplate());
			if (stationMissions[i]->getId() == listOfMission[itPlayerMission]->getIdTemplate()) found = true;
		}
		if (found == false){
			if (stationMissionWidgetBP) {
				Utinymissionwidgetclass *stationMissionWidget = CreateWidget<Utinymissionwidgetclass>(this, stationMissionWidgetBP);
				stationMissionWidget->SetPositionInViewport(FVector2D(300, 70 + 120* currentCount));
				stationMissionWidget->faceValue = stationMissions[i]->getfaceNpc();
				stationMissionWidget->location = stationMissions[i]->getLocation();
				stationMissionWidget->summary = stationMissions[i]->getName();
				stationMissionWidget->id = stationMissions[i]->getId();
				stationMissionWidget->AddToViewport();
				currentCount+=1;
			}
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
		oneMissionWidget->idMission = mission->getId();
		oneMissionWidget->AddToViewport();
	}
}

void AShimPlayerControllerMenu::acceptMission(int32 idMission) {
	UShimServer * instance = UShimServer::getInstance();
	if (instance) {
		FString sIdMission = FString::FromInt(idMission);
		ShimPlayer* currentPlayer = ShimPlayer::getInstance();
		if(currentPlayer){
			FString idPlayer = currentPlayer->getId();
			instance->sendMsg(TEXT("{\"code\":\"3\",\"idmission\":\"" + sIdMission + "\",\"idplayer\":\"" + idPlayer +"\"}"));
		}
	}
}