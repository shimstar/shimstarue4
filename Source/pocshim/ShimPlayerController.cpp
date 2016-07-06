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

void AShimPlayerController::BeginPlay() {
	Super::BeginPlay();
	if (this->HasAuthority() == false) {
		if (missionWidgetBP) {
			widgetMission = CreateWidget<UUserWidgetMissionClass>(this, missionWidgetBP);
			widgetMission->AddToViewport();
			ShimPlayer *currentPlayer = ShimPlayer::getInstance();
			widgetMission->DrawMissionToBP(currentPlayer->getMission()->getName(), currentPlayer->getMission()->getStatus());
		}
	}
}