// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <vector>
#include <iostream>
#include "Json.h"
#include "GameFramework/Actor.h"
#include "ShimEvents.generated.h"

UCLASS()
class POCSHIM_API AShimEvents : public AActor
{
	GENERATED_BODY()
private:


public:	
	// Sets default values for this actor's properties
	AShimEvents();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
