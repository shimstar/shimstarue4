// Fill out your copyright notice in the Description page of Project Settings.

#include "pocshim.h"
#include "ShimEvents.h"

ShimEvents::ShimEvents()
{
	nbShipSpawn = 0;
	evtTemplate = nullptr;
}

ShimEvents::~ShimEvents()
{
}

void ShimEvents::init(TSharedPtr<FJsonObject> evtJs) {
	FString id = evtJs->GetStringField("id");
	evtTemplate = ShimEventsTemplate::getTemplate(id);
	if (evtTemplate == nullptr) {
		evtTemplate = new ShimEventsTemplate();
		evtTemplate->setInfos(evtJs);
	}
}