// Fill out your copyright notice in the Description page of Project Settings.

#include "pocshim.h"
#include "MyGameInstance.h"

UMyGameInstance::UMyGameInstance() {
	if (!UMyGameInstance::instance) {


		ShimServer * instance = ShimServer::getInstance();
		if (instance) {
			bool connected = instance->connect();
			if (connected) {
				//std::thread thread_1 = std::thread(&ShimServer::listen,instance);
				Thread = FRunnableThread::Create(instance, TEXT("FPrimeNumberWorker"), true, true, 0, TPri_BelowNormal);
			}
		}
		UMyGameInstance::instance = this;
	}

}
UMyGameInstance *UMyGameInstance::instance = nullptr;

bool UMyGameInstance::ClientTravelToServer(FString ip) {

	UEngine* const Engine = GetEngine();

	Engine->SetClientTravel(WorldContext->World(), (*ip), TRAVEL_Absolute);
	return true;
}

