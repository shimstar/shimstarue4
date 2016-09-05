// Fill out your copyright notice in the Description page of Project Settings.

#include "pocshim.h"
#include "ShimPlayer.h"

ShimPlayer::ShimPlayer()
{
	listOfPlayer.push_back(this);
}

ShimPlayer* ShimPlayer::getPlayerById(FString id) {
	for (int i = 0; i < listOfPlayer.size(); i++) {
		if (listOfPlayer[i]->getId() == id) return listOfPlayer[i];
	}
	return nullptr;
}

void ShimPlayer::updateMission() {
	
}
FString ShimPlayer::getId()
{
	return id;
}

void ShimPlayer::loadMissions(TArray <TSharedPtr<FJsonValue>> missionsJs) {
	for (int itMission = 0; itMission != missionsJs.Num(); itMission++) {
		TSharedPtr<FJsonObject> tempMissionJs = missionsJs[itMission]->AsObject();
		ShimMission * tempMission = new ShimMission();
		int idtemplate = tempMissionJs->GetIntegerField("idtemplate");
		FString id = tempMissionJs->GetStringField("idtemplate");
		int status = tempMissionJs->GetIntegerField("status");
		tempMission->setId(id);
		tempMission->setTemplate(idtemplate);
		tempMission->setStatus(status);
		listOfMission.push_back(tempMission);
	}


}

void ShimPlayer::setId(FString pid) {
	id = pid;
}
ShimPlayer::~ShimPlayer()
{
}

ShimMission *ShimPlayer::getMission() {
	return NULL;
}

ShimPlayer* ShimPlayer::getInstance() {
	if (!currentPlayer) {
		currentPlayer = new ShimPlayer();
	}
	return currentPlayer;
}

ShimPlayer* ShimPlayer::currentPlayer = nullptr;
std::vector<ShimPlayer *> ShimPlayer::listOfPlayer;