// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ShimServer.h"
#include "Engine/GameInstance.h"
#include "ThreadingBase.h"
#include "ShimMission.h"
#include "MyGameInstance.generated.h"


/**
 * 
 */
UCLASS()
class POCSHIM_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
private:
	ShimMission *mission;

public:
		UFUNCTION(BlueprintCallable, Category = "MyGameInstance")
		bool ClientTravelToServer(FString ip);
		UFUNCTION(BlueprintCallable, Category = "MyGameInstance")
			void initialize();
		FRunnableThread* Thread;

		UFUNCTION(BlueprintCallable, Category = "MyGameInstance")
			void loginShimstar(FString login, FString password);
		UFUNCTION(BlueprintCallable, Category = "MyGameInstance")
			int32 statusLogin();
		UFUNCTION(BlueprintCallable, Category = "MyGameInstance")
			void callServer();
		UFUNCTION(BlueprintCallable, Category = "MyGameInstance")
			bool isConnected();
		UFUNCTION(BlueprintCallable, Category = "Mission")
			FString getMissionName();
		UFUNCTION(BlueprintCallable, Category = "Mission")
			FString getObjectifName();
		UFUNCTION(BlueprintCallable, Category = "Mission")
			int getStatus();
		UFUNCTION(BlueprintCallable, Category = "Mission")
			FString getResult();
};

