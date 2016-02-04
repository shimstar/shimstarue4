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
		UFUNCTION(BlueprintCallable, Category = "MyGameInstance")
		bool ClientTravelToServer(FString ip);
		UFUNCTION(BlueprintCallable, Category = "MyGameInstance")
			void initialize();
		FRunnableThread* Thread;

		UFUNCTION(BlueprintCallable, Category = "MyGameInstance")
			void loginShimstar(FString login, FString password);
		UFUNCTION(BlueprintCallable, Category = "MyGameInstance")
			int32 statusLogin();

};
