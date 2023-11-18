// Fill out your copyright notice in the Description page of Project Settings.


#include "CaptureFunctionLibrary.h"

#include "EditorReimportHandler.h"
#include "HAL/FileManagerGeneric.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "EditorFramework/AssetImportData.h"


TArray<FString> UCaptureFunctionLibrary::GetPNGsOfPath(FString RootFolderFullPath, FString FileName) {

	FPaths::NormalizeDirectoryName(RootFolderFullPath);
	FFileManagerGeneric FileManager;
	TArray<FString> Files;
	Files.Empty();
	
	FString FinalPath = RootFolderFullPath + "/" + FileName;
	IFileManager::Get().FindFiles(Files, *FinalPath, true, false);

	return Files;
}
 
void UCaptureFunctionLibrary::SaveAssetOfPNG()
{
	FString AssetName = TEXT("MyPrimaryDataAsset");
	FString PackageName = TEXT("/Game/");
	
	PackageName += AssetName;
	FString file = "C:\\Unreal\\UE5_HanseiHighSchool\\Saved\\Screenshots\\WindowsEditor\\HighresScreenshot00003.png";

	UPackage* Package = CreatePackage(*PackageName);
	Package->FullyLoad();
	UTexture2D* NewAsset = NewObject<UTexture2D>(
			Package, *AssetName, RF_Public | RF_Standalone | RF_MarkAsRootSet);
	NewAsset->AssetImportData->Update(file);
	auto* ReimportManager = FReimportManager::Instance();
	ReimportManager->Reimport(NewAsset);

	

	FAssetRegistryModule::AssetCreated(NewAsset);
}