// Fill out your copyright notice in the Description page of Project Settings.

#include "pocshim.h"
#include "ShimServer.h"



UShimServer::UShimServer()
{
	connected = false;
	ConnectionSocket = nullptr;
}

UShimServer::~UShimServer()
{
}

void UShimServer::eraseMessage(MessageServer *msg) {
	int index = -1;
	bool found = false;
	for (int i = 0; i < listOfMessage.size(); i++) {
		index = i;
		if (listOfMessage[i] == msg) {
			found = true;
			break;
		}
	}

	if(found) listOfMessage.erase(listOfMessage.begin() + index);

}

MessageServer *UShimServer::getMessage(FString code,bool erase) {
	int index = -1;
	MessageServer *returnValue = nullptr;
	for (int i=0;i < listOfMessage.size();i++) {
		FString val = listOfMessage[i]->getValue("code");
		if (listOfMessage[i]->getValue("code") == code) {
			index = i;
			returnValue = listOfMessage[i];
			break;
		}
	}
	
	if (index != -1) {
		if (erase) listOfMessage.erase(listOfMessage.begin() + index);
	}
	return returnValue;
}

bool UShimServer::connect() {
	this->ConnectionSocket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("default"), false);


	FString address = TEXT("127.0.0.1");
	int32 port = 5000;
	FIPv4Address ip;
	FIPv4Address::Parse(address, ip);
	TSharedRef<FInternetAddr> addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	addr->SetIp(ip.Value);
	addr->SetPort(port);

	bool connected = this->ConnectionSocket->Connect(*addr);
	int32 NewSize = 0;
	int32 ReceiveBufferSize = 8890;

	ConnectionSocket->SetReceiveBufferSize(ReceiveBufferSize, NewSize);

	this->connected = connected;
	
	return connected;
}

bool UShimServer::isConnected() {
	return this->connected;
}

void UShimServer::sendMsg(FString val) {

	TCHAR *serializedChar = val.GetCharArray().GetData();
	int32 size = FCString::Strlen(serializedChar);
	int32 sent = 0;
	bool successful = ConnectionSocket->Send((uint8*)TCHAR_TO_UTF8(serializedChar), size, sent);
}

/*bool UShimServer::Init() {
	return true;
}*/

void UShimServer::getMessages() {
	TArray<uint8> ReceivedData;
	;
	if (connected) {
		uint32 Size;
		while (ConnectionSocket->HasPendingData(Size))
		{
			ReceivedData.Init(FMath::Min(Size, 65507u), 1024);

			int32 Read = 0;
			ConnectionSocket->Recv(ReceivedData.GetData(), ReceivedData.Num(), Read);

			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Data Read! %d"), ReceivedData.Num()));
		}
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		if (ReceivedData.Num() <= 0)
		{
			//	UE_LOG(ShimLog, Warning, TEXT("POGGGGGGGGGGGGG NO DATA RECEIVED"));

		}
		else {
			const FString ReceivedUE4String = StringFromBinaryArray(ReceivedData);
//			UE_LOG(ShimLog, Warning, TEXT("POGGGGGGGGGGGGG %s"), *ReceivedUE4String);
			int posLast = -1;
			ReceivedUE4String.FindLastChar('}', posLast);
			int len = ReceivedUE4String.Len();
			FString tempReceived = ReceivedUE4String.Mid(0, posLast + 1);

			TSharedPtr<FJsonObject> JsonParsed;

			TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(tempReceived);

			if (FJsonSerializer::Deserialize(JsonReader, JsonParsed))
			{	
				MessageServer *temp = new MessageServer();
				temp->setObj(JsonParsed);
				listOfMessage.push_back(temp);
				int ss = listOfMessage.size();
			}
		}
	}
}



UShimServer*  UShimServer::getInstance() {
	if (!UShimServer::instance) {
		UShimServer::instance = new UShimServer();
	}
	return UShimServer::instance;
}

UShimServer* UShimServer::instance = nullptr;

FString UShimServer::StringFromBinaryArray(const TArray<uint8>& BinaryArray)
{
	//Create a string from a byte array!
	std::string cstr(reinterpret_cast<const char*>(BinaryArray.GetData()), BinaryArray.Num());
	return FString(cstr.c_str());
}