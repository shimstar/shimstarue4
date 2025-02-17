// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <vector>
#include <iostream>
#include "OneMissionWidgetClass.h"
#include "ShimMissionTemplate.h"
#include "ShimPlayerControllerMenu.h"
#include "GameFramework/Actor.h"
#include "ShimStation.generated.h"

UCLASS()
class POCSHIM_API AShimStation : public AActor
{
	GENERATED_BODY()
private:
	int id;

public:	
	void loadStation(int);
	

	// Sets default values for this actor's properties
	AShimStation();
	UFUNCTION(BlueprintCallable, Category = "Shimstar|StationUI")
		void ShowListMissions();
	UFUNCTION(BlueprintCallable, Category = "Shimstar|StationUI")
		void ShowMission(int idMission);
		
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
