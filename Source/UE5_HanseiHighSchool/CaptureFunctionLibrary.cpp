// Fill out your copyright notice in the Description page of Project Settings.


#include "CaptureFunctionLibrary.h"
#include "EditorReimportHandler.h"
#include "HAL/FileManagerGeneric.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "EditorFramework/AssetImportData.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"

TArray<FString> UCaptureFunctionLibrary::GetPNGsOfPath(FString RootFolderFullPath, FString FileName) {

	FPaths::NormalizeDirectoryName(RootFolderFullPath);
	FFileManagerGeneric FileManager;
	TArray<FString> Files;
	Files.Empty();
	
	FString FinalPath = RootFolderFullPath + "/" + FileName;
	IFileManager::Get().FindFiles(Files, *FinalPath, true, false);

	return Files;
}
 
UObject* UCaptureFunctionLibrary::SaveAssetOfPath(FString SaveRelativePath, FString FileName,FString ImportAssetPath)
{
	SaveRelativePath += FileName;

	UPackage* Package = CreatePackage(*SaveRelativePath);
	Package->FullyLoad();
	UTexture2D* NewAsset = NewObject<UTexture2D>(
			Package, *FileName, RF_Public | RF_Standalone | RF_MarkAsRootSet);
	NewAsset->AssetImportData->Update(ImportAssetPath);

	FAssetRegistryModule::AssetCreated(NewAsset);
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	AssetRegistryModule.AssetCreated(NewAsset);

	// 새 에셋이 레지스트리에 등록되었는지 확인
	FName PackageName = FName(*NewAsset->GetOutermost()->GetName());
	TArray<FAssetData> AssetDataArray;
	AssetRegistryModule.Get().GetAssetsByPackageName(PackageName, AssetDataArray);

	if (AssetDataArray.Num() > 0)
	{
		FReimportManager::Instance()->Reimport(NewAsset);
	}
	else
	{
		// 에셋이 레지스트리에 등록되지 않았습니다.
	}
	
	return NewAsset;
}

UObject* UCaptureFunctionLibrary::LoadAssetOfPath(const FString LoadRelativePath)
{
	const FString AssetPath = LoadRelativePath;
	const FSoftObjectPath AssetObjectPath(AssetPath);
	UObject* Asset = StaticLoadObject(UObject::StaticClass(), nullptr, *AssetObjectPath.ToString());
	return Asset;
}

bool UCaptureFunctionLibrary::DeleteAssetOfPath(const FString DeleteRelativePath)
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
}

/**
 * @brief 
 * @param ReimportObject editorOnly
 */
void UCaptureFunctionLibrary::ReimportAsset(UObject* ReimportObject)
{
	FReimportManager::Instance()->Reimport(ReimportObject);
}
