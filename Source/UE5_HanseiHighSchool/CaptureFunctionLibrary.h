// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "CaptureFunctionLibrary.generated.h"

/*class UAssetImportData;*/
UCLASS()
class UE5_HANSEIHIGHSCHOOL_API UCaptureFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable,Category="Function")
	static TArray<FString> GetPNGsOfPath(FString RootFolderFullPath, FString FileName);

	UFUNCTION(BlueprintCallable, Category="Funtion")
	static UObject* SaveAssetOfPath(FString SaveRelativePath, FString FileName, FString ImportAssetPath);

	UFUNCTION(BlueprintCallable, Category="Funtion")
	static UObject* LoadAssetOfPath(FString LoadRelativePath);
	
	UFUNCTION(BlueprintCallable, Category="Funtion")
	static bool DeleteAssetOfPath(FString DeleteRelativePath);

	UFUNCTION(BlueprintCallable, Category="Funtion")
	static void ReimportAsset(UObject* ReimportObject);
	
};
