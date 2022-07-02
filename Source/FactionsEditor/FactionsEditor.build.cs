using System.IO;
using UnrealBuildTool;
 
public class FactionsEditor : ModuleRules
{
	public FactionsEditor(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "UnrealEd"});
		PrivateDependencyModuleNames.AddRange(new string[] { "FactionsRuntime" });
 
		// PublicIncludePaths.AddRange(new string[] {"FactionsEditor/Public"});
		// PrivateIncludePaths.AddRange(new string[] {"FactionsEditor/Private"});
	}
}