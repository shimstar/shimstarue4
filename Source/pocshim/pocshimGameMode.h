// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ShimEventsTemplate.h"
#include "GameFramework/GameMode.h"
#include "pocshimGameMode.generated.h"

/**
 * 
 */
UCLASS()
class POCSHIM_API ApocshimGameMode : public AGameMode
{
	GENERATED_BODY()
	
	
public:
	virtual void BeginPlay() override;
	
};
