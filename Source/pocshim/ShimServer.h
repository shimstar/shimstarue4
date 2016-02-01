// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Networking.h"
#include "Sockets.h"
#include "SocketSubsystem.h"
#include "IPv4Address.h"
#include <string>

DECLARE_LOG_CATEGORY_EXTERN(ShimLog, Verbose, All);

/**
 * 
 */
class POCSHIM_API ShimServer : public FRunnable

{
public:
	static ShimServer* getInstance();
	virtual bool Init();
	virtual uint32 Run();
	virtual void Stop();
	bool connect();
private:
	ShimServer();
	~ShimServer();
	
	static ShimServer *instance;

	FSocket* ConnectionSocket;
	FSocket* listener;
	void TCPConnectionListener();
	FString StringFromBinaryArray(const TArray<uint8>& BinaryArray);
	
	


};
