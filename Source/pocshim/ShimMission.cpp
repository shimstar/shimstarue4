// Fill out your copyright notice in the Description page of Project Settings.

#include "pocshim.h"
#include "ShimMission.h"

ShimMission::ShimMission()
{
	missionTemplate = nullptr;
	status = 0;
}

int ShimMission::getIdTemplate() {
	if (missionTemplate) {
		return missionTemplate->getId();
	}
	return 0;
}

void ShimMission::updateObjectif(int ship) {
	objectif->UpdateObjectif(ship);
	status = objectif->getStatus();
}

ShimMission::~ShimMission()
{
}

FString ShimMission::getObjectifText() {
	if (missionTemplate) {
		
	}
	return "";
}

void ShimMission::setTemplate(int idTemplate) {
	missionTemplate = ShimMissionTemplate::getTemplateById(idTemplate);
	std::vector<ShimObjectifTemplate*> listOfObjectifTemplate = missionTemplate->getObjectifs();
	if (listOfObjectifTemplate.size() > 0) {
		for (int i = 0; i < listOfObjectif.size(); i++) {
			ShimObjectif *temp = new ShimObjectif();
			temp->setTemplate(listOfObjectifTemplate[i]);
			listOfObjectif.push_back(temp);
		}
	}
	
}

FString ShimMission::getName() {
	if (missionTemplate) {
		return missionTemplate->getName();
	}
	return "";
}

FString ShimMission::getText() {
	if (missionTemplate) {
		return missionTemplate->getNewText();
	}
	return "";
}