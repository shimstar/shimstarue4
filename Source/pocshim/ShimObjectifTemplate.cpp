// Fill out your copyright notice in the Description page of Project Settings.

#include "pocshim.h"
#include "ShimObjectifTemplate.h"

ShimObjectifTemplate::ShimObjectifTemplate()
{
}

ShimObjectifTemplate::~ShimObjectifTemplate()
{
}

void ShimObjectifTemplate::loadObjectif(TSharedPtr<FJsonObject> objectifJson) {
	id = objectifJson->GetIntegerField("id");
	name = objectifJson->GetStringField("name");
	typeObjectif = objectifJson->GetIntegerField("typeObjectif");
	TSharedPtr<FJsonObject> customObject = objectifJson->GetObjectField("custom");
	nbShip = customObject->GetIntegerField("nbShip");
	TSharedPtr<FJsonObject> eventObject = objectifJson->GetObjectField("event");
	evt = new ShimEventsTemplate();
}