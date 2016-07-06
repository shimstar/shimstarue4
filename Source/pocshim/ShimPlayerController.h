// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "UserWidgetMissionClass.h"
#include "ShimPlayer.h"
#include "ShimPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class POCSHIM_API AShimPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	UUserWidgetMissionClass *widgetMission;
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UUserWidgetMissionClass> missionWidgetBP;
public:
		virtual void Possess(APawn* InPawn) override;
		virtual void BeginPlay() override;
};
