// Fill out your copyright notice in the Description page of Project Settings.

#include "pocshim.h"
#include "ShimStation.h"

void AShimStation::loadMissions() {
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
			listOfMissions.push_back(newMT);
		}
	}
	else {
		UE_LOG(ShimLog, Warning, TEXT("JSON KO"));
	}
}

void AShimStation::loadStation(int pid) {
	id = pid;
	loadMissions();
}

// Sets default values
AShimStation::AShimStation()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AShimStation::BeginPlay()
{
	Super::BeginPlay();
	loadStation(1);
	
}

// Called every frame
void AShimStation::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AShimStation::ShowMission(int idMission) {
	AShimPlayerControllerMenu *Pcontrol = NULL;
	for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
	{
		Pcontrol = Cast<AShimPlayerControllerMenu>(*Iterator);
		break;
	}
	ShimMissionTemplate *mission = NULL;
	for (int i = 0; i < listOfMissions.size(); i++) {
		if (listOfMissions[i]->getId() == idMission) {
			mission = listOfMissions[i];
			break;
		}
	}

	if (Pcontrol && mission) {
		Pcontrol->showMission(mission);
	}
}

void AShimStation::ShowListMissions() {
	AShimPlayerControllerMenu *Pcontrol = NULL;
	for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
	{
		Pcontrol = Cast<AShimPlayerControllerMenu>(*Iterator);
		break;
	}
	if (Pcontrol) {
		Pcontrol->showListOfMission(listOfMissions);
	}
}