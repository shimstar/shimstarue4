// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ShimServer.h"
#include "Engine/GameInstance.h"
#include "ThreadingBase.h"
#include "MyGameInstance.generated.h"


/**
 * 
 */
UCLASS()
class POCSHIM_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
		UFUNCTION(BlueprintCallable, Category = "Session")
		bool ClientTravelToServer(FString ip);
		FRunnableThread* Thread;
		UMyGameInstance();
		static UMyGameInstance *instance;
	
};
