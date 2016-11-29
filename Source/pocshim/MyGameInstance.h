// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ShimServer.h"
#include "ShimPlayer.h"
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

		UFUNCTION(BlueprintCallable, Category = "Shimstar|MyGameInstance")
		bool ClientTravelToServer(FString ip);
		UFUNCTION(BlueprintCallable, Category = "Shimstar|MyGameInstance")
			void initialize();
		FRunnableThread* Thread;

		UFUNCTION(BlueprintCallable, Category = "Shimstar|MyGameInstance")
			void loginShimstar(FString login, FString password);
		UFUNCTION(BlueprintCallable, Category = "Shimstar|MyGameInstance")
			void createUserShimstar(FString login, FString password);
		UFUNCTION(BlueprintCallable, Category = "Shimstar|MyGameInstance")
			int32 statusCreateUser();
		UFUNCTION(BlueprintCallable, Category = "Shimstar|MyGameInstance")
			int32 statusLogin();
		UFUNCTION(BlueprintCallable, Category = "Shimstar|MyGameInstance")
			void callServer();
		UFUNCTION(BlueprintCallable, Category = "Shimstar|MyGameInstance")
			bool isConnected();
		UFUNCTION(BlueprintCallable, Category = "Shimstar|Mission")
			FString getMissionName();
		UFUNCTION(BlueprintCallable, Category = "Shimstar|Mission")
			FString getObjectifName();
		UFUNCTION(BlueprintCallable, Category = "Shimstar|Mission")
			int getStatus();
		UFUNCTION(BlueprintCallable, Category = "Shimstar|Mission")
			FString getResult();
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyGameInstance)
			FString ip;
};

