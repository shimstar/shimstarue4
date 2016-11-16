// Fill out your copyright notice in the Description page of Project Settings.

#include "pocshim.h"
#include "ShimMissionTemplate.h"

void ShimMissionTemplate::init(TSharedPtr<FJsonObject> missionJs) {
	
	id = missionJs->GetIntegerField("id");
	name = missionJs->GetStringField("name");

	type = missionJs->GetStringField("type");
	location = missionJs->GetStringField("location");
	TSharedPtr<FJsonObject> npc = missionJs->GetObjectField("npc");
	nameNpc = npc->GetStringField("name");
	faceNpc = npc->GetStringField("face");
	TSharedPtr<FJsonObject> dialogs = missionJs->GetObjectField("text");
	newText = dialogs->GetStringField("new");
	TSharedPtr<FJsonObject> objectifJs = missionJs->GetObjectField("objectif");
	ShimObjectifTemplate *tempObjectif = new ShimObjectifTemplate();
	tempObjectif->loadObjectif(objectifJs);
	listOfObjectifTemplate.push_back(tempObjectif);
	ShimMissionTemplate::addMissionTemplate(this);
}


ShimMissionTemplate::ShimMissionTemplate()
{
	
}

ShimMissionTemplate::~ShimMissionTemplate()
{
}

void ShimMissionTemplate::addMissionTemplate(ShimMissionTemplate *pMission) {
	bool found = false;
	for (std::vector<ShimMissionTemplate *>::iterator it= listOfMissions.begin(); it < listOfMissions.end(); it++) {
		ShimMissionTemplate *temp = *it;
		if (temp->getId() == pMission->getId()) found = true;
	}

	if (!found) {
		listOfMissions.push_back(pMission);
	}
}

ShimMissionTemplate* ShimMissionTemplate::getTemplateById(int id) {
	if (listOfMissions.size() == 0) {
		ShimMissionTemplate::loadMissions();
	}
	for (int i = 0; i < listOfMissions.size(); i++) {
		if (listOfMissions[i]->getId() == id) return listOfMissions[i];
	}
	return nullptr;
}

std::vector<ShimMissionTemplate *> ShimMissionTemplate::getListOfMissionTemplate() {
	return listOfMissions;
}

void ShimMissionTemplate::loadMissions() {
	FString projectDir = FPaths::GameDir();
	projectDir += "/Content/data/missions_1.json";

	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*projectDir))
	{
		UE_LOG(ShimLog, Warning, TEXT("FILE NOT FOUND %s"), *projectDir);
		return;
	}
	FString FileData = "TEST";
	FFileHelper::LoadFileToString(FileData, *projectDir);
	TSharedPtr<FJsonObject> JsonParsed;

	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(FileData);

	if (FJsonSerializer::Deserialize(JsonReader, JsonParsed))
	{
		TArray <TSharedPtr<FJsonValue>> missionsJs = JsonParsed->GetArrayField("missions");
		for (int itMission = 0; itMission != missionsJs.Num(); itMission++) {
			TSharedPtr<FJsonObject> tempMission = missionsJs[itMission]->AsObject();
			ShimMissionTemplate *newMT = new ShimMissionTemplate();
			newMT->init(tempMission);
		}
	}
	else {
		UE_LOG(ShimLog, Warning, TEXT("JSON KO"));
	}
}

std::vector<ShimMissionTemplate *> ShimMissionTemplate::listOfMissions;