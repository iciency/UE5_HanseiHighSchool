// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5_HanseiHighSchoolGameMode.h"
#include "UE5_HanseiHighSchoolCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE5_HanseiHighSchoolGameMode::AUE5_HanseiHighSchoolGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
