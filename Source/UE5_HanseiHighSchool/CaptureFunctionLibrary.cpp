// Fill out your copyright notice in the Description page of Project Settings.


#include "CaptureFunctionLibrary.h"

#include "HAL/FileManagerGeneric.h"
TArray<FString> UCaptureFunctionLibrary::GetPNGsOfPath(FString RootFolderFullPath, FString FileName) {

	FPaths::NormalizeDirectoryName(RootFolderFullPath);
	FFileManagerGeneric FileManager;
	TArray<FString> Files;
	Files.Empty();
	
	FString FinalPath = RootFolderFullPath + "/" + FileName;
	IFileManager::Get().FindFiles(Files, *FinalPath, true, false);

	return Files;
}