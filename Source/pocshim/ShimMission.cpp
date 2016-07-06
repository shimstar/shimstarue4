// Fill out your copyright notice in the Description page of Project Settings.

#include "pocshim.h"
#include "ShimMission.h"

ShimMission::ShimMission()
{
	id = 1;
	name = "Destroy petit pirate";
	text = "destroy petit pirate";
	status = 0;
	objectif = new ShimObjectif();
}

ShimMission::~ShimMission()
{
}
