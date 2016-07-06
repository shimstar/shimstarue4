// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "ShimMission.h"
#include "UserWidgetMissionClass.generated.h"

/**
 * 
 */
UCLASS()
class POCSHIM_API UUserWidgetMissionClass : public UUserWidget
{
	GENERATED_BODY()
protected:
	UFUNCTION(BlueprintImplementableEvent, Category = MissionUI)
		void DrawMission();
	UFUNCTION(BlueprintImplementableEvent, Category = MissionUI)
		void DrawMissionText();
	UPROPERTY(BlueprintReadOnly, Category = MissionUI)
		FText MissionName;
	UPROPERTY(BlueprintReadOnly, Category = MissionUI)
		int MissionStatus;
	UPROPERTY(BlueprintReadOnly, Category = MissionUI)
		FText MissionText;
	UPROPERTY(BlueprintReadOnly, Category = MissionUI)
		FText ObjectifText;
public:
	void DrawMissionToBP(ShimMission *mission);
	
};
