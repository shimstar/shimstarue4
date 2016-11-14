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
				int32 ll = lom.size();
				if (lom.size() > 0) {
					for (int i = 0; i < lom.size(); i++) {
						int32 s = lom[i]->getStatus();
						if (lom[i]->getStatus() == 0) {
							std::vector<ShimObjectif *>objectifs = lom[i]->getObjectifs();
							if (objectifs.size() > 0) {
								for (int itObj = 0; itObj < objectifs.size(); itObj++) {
									if (objectifs[itObj]->getStatus() == 0) {
										ShimEvents *evtObj = objectifs[itObj]->getEvents();
										if (evtObj != nullptr) {
											ShimEventsTemplate* tplEvent = evtObj->getTemplate();
											if (tplEvent != nullptr) {
												if (evtObj->getNbShipSpawn() == 0) {
													FActorSpawnParameters SpawnInfo;
													FVector  loc = FVector(1000.0f, 1000.0f, 0.0f);
													FRotator rot = FRotator(0.0f, 0.0f, 0.0f);
													GetWorld()->SpawnActor<ADarkFIghterClass>(df_pawnai_bp, loc, rot);
													evtObj->setNbShipSpawn(evtObj->getNbShipSpawn() + 1);
												}
											}
										}
									}
								}
							}
						/*	std::vector<ShimEvents *>events = lom[i]->getEvents();
							int32 l = events.size();
							if (events.size() > 0) {
								for (int itEvent = 0; itEvent < events.size(); itEvent++) {
									ShimEventsTemplate* tplEvent = events[itEvent]->getTemplate();
									if (tplEvent != nullptr) {
										if (events[itEvent]->getNbShipSpawn() == 0) {
											FActorSpawnParameters SpawnInfo;
											FVector  loc = FVector(1000.0f, 1000.0f, 0.0f);
											FRotator rot = FRotator(0.0f, 0.0f, 0.0f);
											GetWorld()->SpawnActor<ADarkFIghterClass>(df_pawnai_bp, loc, rot);
											events[itEvent]->setNbShipSpawn(events[itEvent]->getNbShipSpawn() + 1);
										}
									}
								}
							}*/
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