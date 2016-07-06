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

/**
 * 
 */
//UCLASS(Blueprintable)
class POCSHIM_API UShimServer// : public FRunnable

{
public:
	static UShimServer* getInstance();
	//virtual bool Init();
	//virtual uint32 Run();
	//virtual void Stop();
	bool connect();
	
	MessageServer *getMessage(FString code);
	void getMessages();
	bool isConnected();
	
		void sendMsg(FString);
private:
	UShimServer();
	~UShimServer();
	bool connected;
	static UShimServer *instance;

	FSocket* ConnectionSocket;
	FSocket* listener;
	void TCPConnectionListener();
	FString StringFromBinaryArray(const TArray<uint8>& BinaryArray);
	std::vector<MessageServer*> listOfMessage;
	


};
