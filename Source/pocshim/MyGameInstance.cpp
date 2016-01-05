// Fill out your copyright notice in the Description page of Project Settings.

#include "pocshim.h"
#include "MyGameInstance.h"



bool UMyGameInstance::ClientTravelToServer(FString ip) {

	UEngine* const Engine = GetEngine();

	Engine->SetClientTravel(WorldContext->World(), (*ip), TRAVEL_Absolute);
	return true;
}

