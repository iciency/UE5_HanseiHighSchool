// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CaptureFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class UE5_HANSEIHIGHSCHOOL_API UCaptureFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable,Category="Function")
	static TArray<FString> GetPNGsOfPath(FString RootFolderFullPath, FString FileName);

};
