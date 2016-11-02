// Fill out your copyright notice in the Description page of Project Settings.

#include "pocshim.h"
#include "pocshimGameMode.h"

void ApocshimGameMode::BeginPlay() {
	//ShimEventsTemplate::loadEvents();
	spawn = false;
}

void ApocshimGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FConstPlayerControllerIterator  itPC = GetWorld()->GetPlayerControllerIterator();
	for (itPC; itPC; ++itPC) {
		APlayerController *pc = itPC->Get();
		AShimPlayerController *spc = Cast<AShimPlayerController> (pc);
		if (spc != nullptr) {
			ShimPlayer *pl = spc->getAssociatedPlayer();
			if (pl != nullptr) {
				std::vector<ShimMission *> lom = pl->getListOfMission();
				if (lom.size() > 0) {
					for (int i = 0; i < lom.size(); i++) {
						if (spawn == false) {
							spawn = true;
							FActorSpawnParameters SpawnInfo;
							FVector  loc = FVector(1000.0f, 1000.0f, 0.0f);
							FRotator rot = FRotator(0.0f, 0.0f, 0.0f);
							GetWorld()->SpawnActor<ADarkFIghterClass>(df_pawnai_bp, loc, rot);
							
						}
					}
				}
			}
			

		}

	}
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