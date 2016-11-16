// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <vector>
#include "ShimObjectifTemplate.h"
/**
 * 
 */
class POCSHIM_API ShimMissionTemplate
{
private:
	int id;
	FString name;
	FString nameNpc;
	FString faceNpc;
	FString type;
	FString location;
	FString newText;
	static std::vector<ShimMissionTemplate *> listOfMissions;
	static void addMissionTemplate(ShimMissionTemplate *);
	std::vector<ShimObjectifTemplate *> listOfObjectifTemplate;
public:
	void init(TSharedPtr<FJsonObject>);
	ShimMissionTemplate();
	~ShimMissionTemplate();
	FString getfaceNpc() { return faceNpc; };
	FString getNameNpc() { return nameNpc; };
	FString getLocation() { return location; };
	FString getName() { return name; };
	FString getNewText() { return newText; };
	int getId() { return id; };
	std::vector<ShimObjectifTemplate *> getObjectifs() { return listOfObjectifTemplate; };
	static ShimMissionTemplate *getTemplateById(int);
	static void loadMissions();
	static std::vector<ShimMissionTemplate *> getListOfMissionTemplate();

};

