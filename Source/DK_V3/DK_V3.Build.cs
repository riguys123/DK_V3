// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DK_V3 : ModuleRules
{
	public DK_V3(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
	}
}
