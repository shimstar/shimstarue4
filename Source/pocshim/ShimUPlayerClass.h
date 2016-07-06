// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/Player.h"
#include "ShimMission.h"


#include "ShimUPlayerClass.generated.h"
/**
 * 
 */
UCLASS()
class POCSHIM_API UShimUPlayerClass : public UPlayer
{
	GENERATED_BODY()
private:
	FString name;
	int id;
	ShimMission *mission;

public:
	FString getName() { return name; };
	int getId() { return id; };
	UShimUPlayerClass();
	
	
	
};
