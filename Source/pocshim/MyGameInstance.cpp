// Fill out your copyright notice in the Description page of Project Settings.

#include "pocshim.h"
#include "MyGameInstance.h"


void UMyGameInstance::loginShimstar(FString login, FString password) {
	UShimServer * instance = UShimServer::getInstance();
	if (instance) {
		instance->sendMsg(TEXT("{\"code\":\"1\",\"login\":\"" + login + "\",\"password\":\"" + password + "\"}"));
	}
}

int32 UMyGameInstance::statusLogin() {
	int32 returnStatus = -1;
	UShimServer * instance = UShimServer::getInstance();
	if (instance) {
		MessageServer *message = instance->getMessage("1");
		if (message) {
			returnStatus = FCString::Atoi(*message->getValue("status"));
		}
	}

	return returnStatus;
}

void UMyGameInstance::initialize() {
	UShimServer * instance = UShimServer::getInstance();
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

