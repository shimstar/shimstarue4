// Fill out your copyright notice in the Description page of Project Settings.

#include "pocshim.h"
#include "MessageServer.h"

MessageServer::MessageServer()
{
}

MessageServer::~MessageServer()
{
}

void MessageServer::setObj(TSharedPtr<FJsonObject> obj) {
	JsonParsed = obj;
}

FString MessageServer::getValue(FString key) {
	if (JsonParsed->HasField(key)) {
		return JsonParsed->GetStringField(key);
	}
	return "";
}