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
 
/*bool UCaptureFunctionLibrary::SaveAssetOfPath(FString SaveRelativePath, FString FileName,FString ImportAssetPath)
{
	SaveRelativePath += FileName;

	UPackage* Package = CreatePackage(*SaveRelativePath);
	Package->FullyLoad();
	UTexture2D* NewAsset = NewObject<UTexture2D>(
			Package, *FileName, RF_Public | RF_Standalone | RF_MarkAsRootSet);
	NewAsset->AssetImportData->Update(ImportAssetPath);

	if(FReimportManager::Instance()->CanReimport(NewAsset) == false)
	{
		return false;
	}
	FReimportManager::Instance()->Reimport(NewAsset);
	
	FAssetRegistryModule::AssetCreated(NewAsset);
	return true;
}

UObject* UCaptureFunctionLibrary::LoadAssetOfPath(FString LoadRelativePath)
{
	const FString AssetPath = LoadRelativePath;
	const FSoftObjectPath AssetObjectPath(AssetPath);
	UObject* Asset = StaticLoadObject(UObject::StaticClass(), nullptr, *AssetObjectPath.ToString());
	return Asset;
}

bool UCaptureFunctionLibrary::DeleteAssetOfPath(FString DeleteRelativePath)
{
	const FString AssetPath = DeleteRelativePath;
	const FSoftObjectPath AssetObjectPath(AssetPath);
	UObject* Asset = StaticLoadObject(UObject::StaticClass(), nullptr, *AssetObjectPath.ToString());
	if (Asset == nullptr)
	{
		return false;
	}
	FAssetRegistryModule::AssetDeleted(Asset);
	return true;
}*/
