// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ShimServer.h"
#include "GameFramework/PlayerController.h"
#include "UserWidgetMissionClass.h"
#include "ShimPlayer.h"
#include <iostream>
#include <exception>
#include "ShimPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class POCSHIM_API AShimPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	ShimPlayer *associatedPlayer;
	UPROPERTY()
	UUserWidgetMissionClass *widgetMission = nullptr;
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UUserWidgetMissionClass> missionWidgetBP;
	int initialise = 0;
	void init();
public:
		virtual void Possess(APawn* InPawn) override;
		virtual void BeginPlay() override;
		UFUNCTION(BlueprintCallable, Category = "Shimstar|ShimPlayerController")
		void updateMission();
		UFUNCTION(Server,Reliable, WithValidation, BlueprintCallable, Category = "Shimstar|ShimPlayerController")
			void setIdPlayerToServer(const FString& id);
		UFUNCTION(Client, Reliable, WithValidation, BlueprintCallable, Category = "Shimstar|ShimPlayerController")
			void postLogin();
		UFUNCTION(BlueprintCallable, Category = "Shimstar|ShimPlayerController")
			void checkMessageServer();
		ShimPlayer* getAssociatedPlayer() { return associatedPlayer; };

};
