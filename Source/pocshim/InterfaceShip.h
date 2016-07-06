// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "InterfaceShip.generated.h"
/**
 * 
 */
UINTERFACE(MinimalAPI)
class UInterfaceShip : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class IInterfaceShip
{
	GENERATED_IINTERFACE_BODY()

public:

	//UFUNCTION(BlueprintImplementableEvent, Category = "Ship")
		virtual float GetHealth();
};
