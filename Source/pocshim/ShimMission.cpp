// Fill out your copyright notice in the Description page of Project Settings.

#include "pocshim.h"
#include "ShimMission.h"

ShimMission::ShimMission()
{
	id = 1;
	name = "Destroy petit pirate";
	text = "Un pirate s'amuse dans la zone\n\
S'il vous plait, arretez le!!\n\
Detruisez le";
	status = 0;
	objectif = new ShimObjectif();
}

ShimMission::~ShimMission()
{
}
