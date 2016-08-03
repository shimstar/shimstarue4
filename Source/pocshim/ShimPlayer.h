// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <vector>
#include "ShimMission.h"
/**
 * 
 */
class POCSHIM_API ShimPlayer
{
private:
	int id;
	std::vector<ShimMission *> listOfMission;
	ShimPlayer();
	~ShimPlayer();
	static ShimPlayer *currentPlayer;
public:
	static ShimPlayer *getInstance();
	ShimMission *getMission();
	std::vector<ShimMission *> getListOfMission() { return listOfMission; };
	void updateMission();
};
