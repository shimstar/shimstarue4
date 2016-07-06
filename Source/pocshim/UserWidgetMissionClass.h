// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "UserWidgetMissionClass.generated.h"

/**
 * 
 */
UCLASS()
class POCSHIM_API UUserWidgetMissionClass : public UUserWidget
{
	GENERATED_BODY()
protected:
	UFUNCTION(BlueprintImplementableEvent, Category = UI)
		void DrawMission();
	UPROPERTY(BlueprintReadOnly)
		FText MissionName;
	UPROPERTY(BlueprintReadOnly)
		int MissionStatus;
public:
	void DrawMissionToBP(FString MissionName, int MissionStatus);
	
};
