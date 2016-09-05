// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <vector>
#include "ShimMission.h"
/**
 * 
 */
class POCSHIM_API ShimPlayer
{
private:
	FString id;
	std::vector<ShimMission *> listOfMission;
	static ShimPlayer *currentPlayer;
	static std::vector<ShimPlayer *> listOfPlayer;
public:
	ShimPlayer();
	~ShimPlayer();
	static ShimPlayer *getInstance();
	ShimMission *getMission();
	std::vector<ShimMission *> getListOfMission() { return listOfMission; };
	void updateMission();
	FString getId(); 
	void setId(FString id);
	void loadMissions(TArray <TSharedPtr<FJsonValue>>);

	ShimPlayer* getPlayerById(FString id);

};
