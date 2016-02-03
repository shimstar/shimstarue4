// Fill out your copyright notice in the Description page of Project Settings.

#include "pocshim.h"
#include "MyGameInstance.h"





void UMyGameInstance::initialize() {
	ShimServer * instance = ShimServer::getInstance();
	if (instance) {
		bool connected = instance->connect();
		if (connected) {
			Thread = FRunnableThread::Create(instance, TEXT("FPrimeNumberWorker"),  0, TPri_BelowNormal);
		}
	}
}

bool UMyGameInstance::ClientTravelToServer(FString ip) {

	UEngine* const Engine = GetEngine();

	Engine->SetClientTravel(WorldContext->World(), (*ip), TRAVEL_Absolute);
	return true;
}

