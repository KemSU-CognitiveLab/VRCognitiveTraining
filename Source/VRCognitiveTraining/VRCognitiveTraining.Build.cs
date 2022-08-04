// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class VRCognitiveTraining : ModuleRules
{
	public VRCognitiveTraining(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "VRExperimentsBase" });

		PrivateDependencyModuleNames.AddRange(new string[] { "SRanipal", "SRanipalEye", "HeadMountedDisplay", "SlateCore" });

		PrivateIncludePaths.AddRange(new string[] {
			"../Plugins/VRExperimentsBase/Source/ThirdPartyLibs",
			"../Plugins/SRanipal/Source/SRanipal/Public/Eye"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
