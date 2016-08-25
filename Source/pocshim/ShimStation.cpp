// Fill out your copyright notice in the Description page of Project Settings.

#include "pocshim.h"
#include "ShimStation.h"


void AShimStation::loadStation(int pid) {
	id = pid;
}

// Sets default values
AShimStation::AShimStation()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AShimStation::BeginPlay()
{
	Super::BeginPlay();
	loadStation(1);
	
}

// Called every frame
void AShimStation::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AShimStation::ShowMission(int idMission) {
	AShimPlayerControllerMenu *Pcontrol = NULL;
	for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
	{
		Pcontrol = Cast<AShimPlayerControllerMenu>(*Iterator);
		break;
	}
	ShimMissionTemplate *mission = ShimMissionTemplate::getTemplateById(idMission);
	
	if (Pcontrol && mission) {
		Pcontrol->showMission(mission);
	}
}

void AShimStation::ShowListMissions() {
	AShimPlayerControllerMenu *Pcontrol = NULL;
	for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
	{
		Pcontrol = Cast<AShimPlayerControllerMenu>(*Iterator);
		break;
	}
	if (Pcontrol) {
		Pcontrol->showListOfMission(ShimMissionTemplate::getListOfMissionTemplate());
	}
}