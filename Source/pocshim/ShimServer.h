// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Networking.h"
#include "Sockets.h"
#include "Json.h"
#include "SocketSubsystem.h"
#include "IPv4Address.h"
#include "MessageServer.h"
#include <string>
#include <vector>

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
	UFUNCTION(BlueprintCallable, Category = "ShimServer")
	MessageServer *getMessage(FString code);


	UFUNCTION(BlueprintCallable, Category = "ShimServer")
		void sendMsg(FString);
private:
	ShimServer();
	~ShimServer();
	
	static ShimServer *instance;

	FSocket* ConnectionSocket;
	FSocket* listener;
	void TCPConnectionListener();
	FString StringFromBinaryArray(const TArray<uint8>& BinaryArray);
	std::vector<MessageServer*> listOfMessage;
	


};
