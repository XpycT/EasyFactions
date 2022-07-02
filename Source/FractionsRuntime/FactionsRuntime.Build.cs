// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class FactionsRuntime : ModuleRules
{
	public FactionsRuntime(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange(new string[]
		{
			Path.Combine(ModuleDirectory, "Public/Factions"),
			Path.Combine(ModuleDirectory, "Public/Data"),
		});

		PublicDependencyModuleNames.AddRange( new string[] { "Core" });
		PrivateDependencyModuleNames.AddRange( new string[] { "CoreUObject", "Engine", "AIModule" });
		if (Target.bBuildEditor == true)
		{
			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"SlateCore",
					"Slate"
				}
			);
		}
	}
}
