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
	UE_LOG(ShimLog, Warning, TEXT("TOTO2"));
	UShimServer * instance = UShimServer::getInstance();
	if (instance) {
		MessageServer *message = instance->getMessage("1");
		UE_LOG(ShimLog, Warning, TEXT("TOTO"));
		if (message) {
			UE_LOG(ShimLog, Warning, TEXT("TTTT %d"), FCString::Atoi(*message->getValue("status")));
			returnStatus = FCString::Atoi(*message->getValue("status"));
		}
	}

	return returnStatus;
}

bool UMyGameInstance::isConnected() {
	UShimServer * instance = UShimServer::getInstance();
	if (instance) {
		return instance->isConnected();
	}
	else {
		return false;
	}
}

void UMyGameInstance::initialize() {
	UShimServer * instance = UShimServer::getInstance();
	if (instance) {
		bool connected = instance->connect();
		if (connected) {
			//Thread = FRunnableThread::Create(instance, TEXT("FPrimeNumberWorker"),  0, TPri_BelowNormal);
		}
	}
}

void UMyGameInstance::callServer() {
	UShimServer * instance = UShimServer::getInstance();
	if (instance) {
		if (instance->isConnected()) {
			instance->getMessages();
		}
	}
}


bool UMyGameInstance::ClientTravelToServer(FString ip) {

	UEngine* const Engine = GetEngine();

	Engine->SetClientTravel(WorldContext->World(), (*ip), TRAVEL_Absolute);
	return true;
}

