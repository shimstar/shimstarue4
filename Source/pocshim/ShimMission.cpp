// Fill out your copyright notice in the Description page of Project Settings.

#include "pocshim.h"
#include "ShimMission.h"

ShimMission::ShimMission()
{
	missionTemplate = nullptr;
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
	return objectif->getObjectif();
}

void ShimMission::setTemplate(int idTemplate) {
	missionTemplate = ShimMissionTemplate::getTemplateById(idTemplate);
}