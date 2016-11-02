// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ShimEventsTemplate.h"
#include "ShimServer.h"
#include "ShimPlayerController.h"
#include "DarkFIghterClass.h"
#include "GameFramework/GameMode.h"
#include "pocshimGameMode.generated.h"

/**
 * 
 */
UCLASS()
class POCSHIM_API ApocshimGameMode : public AGameMode
{
	GENERATED_BODY()
		bool spawn;
	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	UFUNCTION(BlueprintCallable, Category = "Shimstar|MyGameMode")
		void callServer();
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<ADarkFIghterClass> df_pawnai_bp;
	
};
