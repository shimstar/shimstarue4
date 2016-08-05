// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <vector>
#include "OneMissionWidgetClass.h"
#include "tinymissionwidgetclass.h"
#include "ShimMissionTemplate.h"
#include "UserWidgetMissionClass.h"
#include "GameFramework/PlayerController.h"
#include "ShimPlayerControllerMenu.generated.h"

/**
 * 
 */
UCLASS()
class POCSHIM_API AShimPlayerControllerMenu : public APlayerController
{
	GENERATED_BODY()
private:
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<Utinymissionwidgetclass> stationMissionWidgetBP;
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UOneMissionWidgetClass> oneMissionWidgetBP;
public:
	void showListOfMission(std::vector<ShimMissionTemplate *>);
	void showMission(ShimMissionTemplate *);

	void ShowMission();

	
};
