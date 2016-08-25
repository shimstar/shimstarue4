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
		bool connected = instance->isConnected();
		if (!connected) {
			connected = instance->connect();
		}
		if (connected) {
			MessageServer *message = instance->getMessage("1");
			if (message) {
				returnStatus = FCString::Atoi(*message->getValue("status"));
				if (returnStatus == 1) {
					ShimPlayer *currentPlayer = ShimPlayer::getInstance();
					if (currentPlayer) {
						TSharedPtr<FJsonObject> jsonObj = message->getObj();
						TSharedPtr<FJsonObject> userJson = jsonObj->GetObjectField("userJson");
						FString tempId = userJson->GetStringField("id");
						currentPlayer->setId(tempId);
						TArray <TSharedPtr<FJsonValue>> missionsJs = userJson->GetArrayField("missions");
						currentPlayer->loadMissions(missionsJs);

					}
				}
			}
		}
	}

	return returnStatus;
}

FString UMyGameInstance::getMissionName() {
	FString resultName = "";
	if (mission) {
		resultName = mission->getName();
	}
	return resultName;
}

FString UMyGameInstance::getObjectifName() {
	FString resultName = "";

	return resultName;
}

int UMyGameInstance::getStatus() {
	int resultStatus = 0;

	return resultStatus;
}

FString UMyGameInstance::getResult() {
	FString returnResult = "";

	return returnResult;
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
//	if(this->HasAuthority() == false){
		UShimServer * instance = UShimServer::getInstance();
		if (instance) {
			bool connected = instance->isConnected();
			if (!connected) {
				connected = instance->connect();
				//Thread = FRunnableThread::Create(instance, TEXT("FPrimeNumberWorker"),  0, TPri_BelowNormal);
			}
		}
	//}
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

