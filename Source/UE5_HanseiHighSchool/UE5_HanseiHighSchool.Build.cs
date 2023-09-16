// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE5_HanseiHighSchool : ModuleRules
{
	public UE5_HanseiHighSchool(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
