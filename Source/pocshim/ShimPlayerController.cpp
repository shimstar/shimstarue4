// Fill out your copyright notice in the Description page of Project Settings.

#include "pocshim.h"
#include "ShimPlayerController.h"

void AShimPlayerController::Possess(APawn* InPawn)
{
	Super::Possess(InPawn);
	if(this->HasAuthority() == false ){
		if (missionWidgetBP) {
			widgetMission = CreateWidget<UUserWidgetMissionClass>(this, missionWidgetBP);
			widgetMission->AddToViewport();
		}
	}	
}

void AShimPlayerController::checkMessageServer() {
	UShimServer * instance = UShimServer::getInstance();
	if (instance) {
		bool connected = instance->isConnected();
		if (!connected) {
			connected = instance->connect();
		}
		if (connected) {
			if (this->HasAuthority() == true) {
				MessageServer *message = instance->getMessage("6",false);
				if (message) {
					int32 returnStatus = FCString::Atoi(*message->getValue("status"));
					if (returnStatus == 1) {
						if (associatedPlayer) {
							TSharedPtr<FJsonObject> jsonObj = message->getObj();
							TSharedPtr<FJsonObject> userJson = jsonObj->GetObjectField("userJson");
							FString tempId = userJson->GetStringField("id");
							if (tempId == associatedPlayer->getId()){
								TArray <TSharedPtr<FJsonValue>> missionsJs = userJson->GetArrayField("missions");
								associatedPlayer->loadMissions(missionsJs);
								instance->eraseMessage(message);
							}
						}
					}
				}
			}
		}
	}
}

void AShimPlayerController::BeginPlay() {
	Super::BeginPlay();
	associatedPlayer = nullptr;
	if (this->HasAuthority() == false) {
		ShimPlayer *currentPlayer = ShimPlayer::getInstance();
		if(currentPlayer){
			if (missionWidgetBP) {
				widgetMission = CreateWidget<UUserWidgetMissionClass>(this, missionWidgetBP);
				if(currentPlayer->getMission()){
					widgetMission->AddToViewport();
					widgetMission->DrawMissionToBP(currentPlayer->getMission());
				}	
			}
		}
	}
	
}

void AShimPlayerController::postLogin_Implementation() {
	ShimPlayer *currentPlayer = ShimPlayer::getInstance();
	if (currentPlayer) {
		setIdPlayerToServer(currentPlayer->getId());
	}
}


bool AShimPlayerController::postLogin_Validate() {
	return true;
}


void AShimPlayerController::setIdPlayerToServer_Implementation(const FString& id) {
	if (associatedPlayer != nullptr) 	UE_LOG(ShimLog, Warning, TEXT("AShimPlayerController::setIdPlayerToServer_Implementation :: assocaited player not null! !!! ! !"));
	associatedPlayer = new ShimPlayer();
	associatedPlayer->setId(id);
	UShimServer * instance = UShimServer::getInstance();
	if (instance) {
		instance->sendMsg(TEXT("{\"code\":\"6\",\"id\":\"" + id + "\"}"));
	}
}

bool AShimPlayerController::setIdPlayerToServer_Validate(const FString &id) {
	return true;
}

void AShimPlayerController::updateMission() {
	if (this->HasAuthority() == false) {
		ShimPlayer *currentPlayer = ShimPlayer::getInstance();

		currentPlayer->updateMission();
		if (currentPlayer->getMission()) {
			if (missionWidgetBP) {
				if (!widgetMission->IsInViewport()) {
					widgetMission->AddToViewport();
				}
				widgetMission->DrawMissionToBP(currentPlayer->getMission());
			}
		}
		else {
			if (widgetMission->IsInViewport()) {
				widgetMission->RemoveFromViewport();
			}
		}
	}
}