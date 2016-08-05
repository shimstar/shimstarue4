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
	UPROPERTY(Category = "shimstar|station", EditAnywhere, BlueprintReadWrite) 
		FString faceValue;
	
	
	
};
