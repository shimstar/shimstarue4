// Fill out your copyright notice in the Description page of Project Settings.

#include "pocshim.h"
#include "ShimPlayer.h"

ShimPlayer::ShimPlayer()
{
}

void ShimPlayer::updateMission() {
	
}

ShimPlayer::~ShimPlayer()
{
}

ShimMission *ShimPlayer::getMission() {
	return NULL;
}

ShimPlayer* ShimPlayer::getInstance() {
	if (!currentPlayer) {
		currentPlayer = new ShimPlayer();
	}
	return currentPlayer;
}

ShimPlayer* ShimPlayer::currentPlayer = nullptr;