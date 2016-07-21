// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ShimMission.h"
/**
 * 
 */
class POCSHIM_API ShimPlayer
{
private:
	int id;
	ShimMission *mission;
	ShimPlayer();
	~ShimPlayer();
	static ShimPlayer *currentPlayer;
public:
	static ShimPlayer *getInstance();
	ShimMission *getMission();
	void updateMission();
};
