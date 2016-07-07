// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 * 
 */
class POCSHIM_API ShimObjectif
{
private:
	int id;
	FString name;
	int nbShip;
	int actualNbShip;
	int typeObjectif;
	int status;
public:
	FString getObjectif();
	void UpdateObjectif(int ship);
	int getStatus() { return status; };
	ShimObjectif();
	~ShimObjectif();
};
