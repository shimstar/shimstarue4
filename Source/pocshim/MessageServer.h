// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 * 
 */
class POCSHIM_API MessageServer
{
public:
	MessageServer();
	~MessageServer();
	UFUNCTION(BlueprintCallable, Category = "MessageServer")
	FString getValue(FString);
	void setObj(TSharedPtr<FJsonObject>);
	TSharedPtr<FJsonObject> getObj();

private:
	TSharedPtr<FJsonObject> JsonParsed;
};
