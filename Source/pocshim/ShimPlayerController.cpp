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
			
			ShimPlayer *currentPlayer = ShimPlayer::getInstance();
			if(currentPlayer->getMission()){
				widgetMission->AddToViewport();
				widgetMission->DrawMissionToBP(currentPlayer->getMission());
			}
			
			
		}
	}
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