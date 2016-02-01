// Fill out your copyright notice in the Description page of Project Settings.

#include "pocshim.h"
#include "ShimServer.h"


DEFINE_LOG_CATEGORY(ShimLog);
ShimServer::ShimServer()
{
}

ShimServer::~ShimServer()
{
}
void ShimServer::TCPConnectionListener() {
	
}


bool ShimServer::connect() {
	this->ConnectionSocket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("default"), false);


	FString address = TEXT("127.0.0.1");
	int32 port = 5000;
	FIPv4Address ip;
	FIPv4Address::Parse(address, ip);
	TSharedRef<FInternetAddr> addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	addr->SetIp(ip.GetValue());
	addr->SetPort(port);

	bool connected = this->ConnectionSocket->Connect(*addr);
	int32 NewSize = 0;
	int32 ReceiveBufferSize = 8890;

	ConnectionSocket->SetReceiveBufferSize(ReceiveBufferSize, NewSize);

	//GetWorldTimerManager();
	//listener = FTcpSocketBuilder("shimstar");//.BoundToEndpoint(Endpoint);
	/*	.AsReusable()
		.BoundToEndpoint(Endpoint)
		.Listening(8);

	//Set Buffer Size
	int32 NewSize = 0;
	listener->SetReceiveBufferSize(8890, NewSize);*/
//	GetWorldTimerManager().SetTimer(this,
//		&ShimServer::TCPConnectionListener, 0.01, true);

	/*FIPv4Address ip;
	FIPv4Address::Parse(address, ip);

	*/
	/*TSharedRef<FInternetAddr> addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	addr->SetIp(ip.GetValue());
	addr->SetPort(port);
	
	bool connected = this->ConnectionSocket->Connect(*addr);
	*/



	return true;
}

bool ShimServer::Init() {
	this->ConnectionSocket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("default"), false);


	FString address = TEXT("127.0.0.1");
	int32 port = 5000;
	FIPv4Address ip;
	FIPv4Address::Parse(address, ip);
	TSharedRef<FInternetAddr> addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	addr->SetIp(ip.GetValue());
	addr->SetPort(port);

	bool connected = this->ConnectionSocket->Connect(*addr);
	int32 NewSize = 0;
	int32 ReceiveBufferSize = 8890;

	ConnectionSocket->SetReceiveBufferSize(ReceiveBufferSize, NewSize);
	return connected;
}

uint32 ShimServer::Run() {

	
	while(1){
		TArray<uint8> ReceivedData;

		uint32 Size;
		while (ConnectionSocket->HasPendingData(Size))
		{
			ReceivedData.Init(FMath::Min(Size, 65507u));

			int32 Read = 0;
			ConnectionSocket->Recv(ReceivedData.GetData(), ReceivedData.Num(), Read);

			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Data Read! %d"), ReceivedData.Num()));
		}
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		if (ReceivedData.Num() <= 0)
		{
		//	UE_LOG(ShimLog, Warning, TEXT("POGGGGGGGGGGGGG NO DATA RECEIVED"));
			
		}else{
			//UE_LOG(ShimLog, Warning, TEXT("PPPPPP DATA RECEIVED %d"), ReceivedData.Num());
			const FString ReceivedUE4String = StringFromBinaryArray(ReceivedData);
			UE_LOG(ShimLog, Warning, TEXT("PPPP %s"),*ReceivedUE4String);
		}
	}
	return 0;
}

void ShimServer::Stop() {

}



ShimServer*  ShimServer::getInstance() {
	if (!ShimServer::instance) {
		ShimServer::instance = new ShimServer();
	}
	return ShimServer::instance;
}

ShimServer* ShimServer::instance = nullptr;

FString ShimServer::StringFromBinaryArray(const TArray<uint8>& BinaryArray)
{
	//Create a string from a byte array!
	std::string cstr(reinterpret_cast<const char*>(BinaryArray.GetData()), BinaryArray.Num());
	return FString(cstr.c_str());
}