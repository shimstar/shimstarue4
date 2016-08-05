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

void AShimStation::ShowListMissions() {
	AShimPlayerControllerMenu *Pcontrol = NULL;
	for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
	{
		Pcontrol = Cast<AShimPlayerControllerMenu>(*Iterator);
		break;
	}
	if (Pcontrol) {
		UE_LOG(ShimLog, Warning, TEXT("Show List Missions"));
		Pcontrol->showListOfMission(listOfMissions);
	}
	/*UE_LOG(ShimLog, Warning, TEXT("Show List Missions"));
	for (int i = 0; i < listOfMissions.size(); i++) {
		UE_LOG(ShimLog, Warning, TEXT("Show List Missions 2"));
		if (stationWidgetBP) {
			UE_LOG(ShimLog, Warning, TEXT("Show List Missions 3"));
			APlayerController *Pcontrol = NULL;
			for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
			{
				Pcontrol = *Iterator;
				break;
			}
			UE_LOG(ShimLog, Warning, TEXT("Show List Missions 4"));
			if (Pcontrol) {
				UE_LOG(ShimLog, Warning, TEXT("Show List Missions 5"));
				UStationWidgetClass *widgetMission = NULL;
				widgetMission = CreateWidget<UStationWidgetClass>(Pcontrol, stationWidgetBP);
				widgetMission->AddToViewport();
			}
			
		}
	}*/
}