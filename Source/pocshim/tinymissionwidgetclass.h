// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "tinymissionwidgetclass.generated.h"

/**
 * 
 */
UCLASS()
class POCSHIM_API Utinymissionwidgetclass : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(Category = "Shimstar|StationUI", EditAnywhere, BlueprintReadWrite) 
		FString faceValue;
	UPROPERTY(Category = "Shimstar|StationUI", EditAnywhere, BlueprintReadWrite)
		FString summary;
	UPROPERTY(Category = "Shimstar|StationUI", EditAnywhere, BlueprintReadWrite)
		FString location;
	
	
	
};
