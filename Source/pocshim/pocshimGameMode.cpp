// Fill out your copyright notice in the Description page of Project Settings.

#include "pocshim.h"
#include "pocshimGameMode.h"

void ApocshimGameMode::BeginPlay() {
	ShimEventsTemplate::loadEvents();
}


void ApocshimGameMode::callServer() {
	UShimServer * instance = UShimServer::getInstance();
	if (instance) {
		bool connected = instance->isConnected();
		if (!connected) {
			connected = instance->connect();
		}else{
			instance->getMessages();
		}
	}
}