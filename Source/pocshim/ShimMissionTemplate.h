// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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
};

