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
			widgetMission->DrawMissionToBP(currentPlayer->getMission());
			
		}
	}
}

void AShimPlayerController::updateMission() {
	if (this->HasAuthority() == false) {
		ShimPlayer *currentPlayer = ShimPlayer::getInstance();
		UE_LOG(ShimLog, Warning, TEXT("UPDATE MISSION?"));
		currentPlayer->updateMission();
		if (missionWidgetBP) {
			widgetMission->DrawMissionToBP(currentPlayer->getMission());
		}
	}
}