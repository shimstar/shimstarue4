// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "OneMissionWidgetClass.generated.h"

/**
 * 
 */
UCLASS()
class POCSHIM_API UOneMissionWidgetClass : public UUserWidget
{
	GENERATED_BODY()
	
	
public:
	UPROPERTY(Category = "Shimstar|StationUI", EditAnywhere, BlueprintReadWrite)
		FString faceValue;
	UPROPERTY(Category = "Shimstar|StationUI", EditAnywhere, BlueprintReadWrite)
		FString faceNameValue;
	UPROPERTY(Category = "Shimstar|StationUI", EditAnywhere, BlueprintReadWrite)
		FString summary;
	UPROPERTY(Category = "Shimstar|StationUI", EditAnywhere, BlueprintReadWrite)
		FString text;
	UPROPERTY(Category = "Shimstar|StationUI", EditAnywhere, BlueprintReadWrite)
		FString objectifs;
	UPROPERTY(Category = "Shimstar|StationUI", EditAnywhere, BlueprintReadWrite)
		int32 idMission;
	
};
