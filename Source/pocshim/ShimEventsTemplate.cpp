// Fill out your copyright notice in the Description page of Project Settings.

#include "pocshim.h"
#include "ShimEventsTemplate.h"


void ShimEventsTemplate::setInfos(TSharedPtr<FJsonObject> peventJs) {
	name = peventJs->GetStringField("name");
	id = peventJs->GetIntegerField("id");
	relatedMission = peventJs->GetIntegerField("relatedmission");
	possibility = peventJs->GetIntegerField("possibility");
	reproduceEvenMissionFinished = peventJs->GetBoolField("reproduceEvenMissionFinished");
	TSharedPtr<FJsonObject> spawnObject = peventJs->GetObjectField("spawn");
	spawnArchetype = spawnObject->GetStringField("ship");
	nbShip = spawnObject->GetIntegerField("nbship");
	spawnX = spawnObject->GetIntegerField("spawnX");
	spawnY = spawnObject->GetIntegerField("spawnY");
	spawnZ = spawnObject->GetIntegerField("spawnZ");

}

void ShimEventsTemplate::loadEvents() {
	FString projectDir = FPaths::GameDir();
	projectDir += "/Content/data/events.json";
	//

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
		TArray <TSharedPtr<FJsonValue>> zonesJs = JsonParsed->GetArrayField("Zones");
		for (int itZones = 0; itZones != zonesJs.Num(); itZones++) {
			TSharedPtr<FJsonObject> temp = zonesJs[itZones]->AsObject();
			TArray <TSharedPtr<FJsonValue>> eventJs = temp->GetArrayField("events");
			for (int itEvents = 0; itEvents != eventJs.Num(); itEvents++) {
				TSharedPtr<FJsonObject> tempEventJs = eventJs[itEvents]->AsObject();
				//FString nameEvents = tempEventJs->GetStringField("name");
				ShimEventsTemplate *temp = new ShimEventsTemplate();
				temp->setInfos(tempEventJs);
				ShimEventsTemplate::listOfEvents.push_back(temp);
			}

		}
	}
	else {
		UE_LOG(ShimLog, Warning, TEXT("JSON KO"));
	}

}
ShimEventsTemplate::ShimEventsTemplate()
{
}

ShimEventsTemplate::~ShimEventsTemplate()
{
}

std::vector<ShimEventsTemplate *> ShimEventsTemplate::listOfEvents;