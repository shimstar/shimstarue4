// Fill out your copyright notice in the Description page of Project Settings.

#include "pocshim.h"
#include "ShimMissionTemplate.h"

void ShimMissionTemplate::init(TSharedPtr<FJsonObject> missionJs) {
	id = missionJs->GetIntegerField("id");
	name = missionJs->GetStringField("name");
	type = missionJs->GetStringField("type");
	TSharedPtr<FJsonObject> npc = missionJs->GetObjectField("npc");
	nameNpc = npc->GetStringField("name");
	faceNpc = npc->GetStringField("face");
}


ShimMissionTemplate::ShimMissionTemplate()
{

}

ShimMissionTemplate::~ShimMissionTemplate()
{
}
