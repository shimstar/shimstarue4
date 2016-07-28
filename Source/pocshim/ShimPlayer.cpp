// Fill out your copyright notice in the Description page of Project Settings.

#include "pocshim.h"
#include "ShimPlayer.h"

ShimPlayer::ShimPlayer()
{
	/*
	FString projectDir = FPaths::GameDir();
	UE_LOG(ShimLog, Warning, TEXT("POGGGGGGGGGGGGG %s"),*projectDir);
	projectDir += "/Content/data/mission.json";
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
		UE_LOG(ShimLog, Warning, TEXT("JSON OK"));
	}
	else {
		UE_LOG(ShimLog, Warning, TEXT("JSON KO"));
	}
	*/
	//mission = new ShimMission();
	mission = NULL;
}

void ShimPlayer::updateMission() {
	if (mission)
		mission->updateObjectif(1);
}

ShimPlayer::~ShimPlayer()
{
}

ShimMission *ShimPlayer::getMission() {
	return mission;
}

ShimPlayer* ShimPlayer::getInstance() {
	if (!currentPlayer) {
		currentPlayer = new ShimPlayer();
	}
	return currentPlayer;
}

ShimPlayer* ShimPlayer::currentPlayer = nullptr;