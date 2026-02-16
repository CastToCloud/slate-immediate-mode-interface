using UnrealBuildTool;

public class SlateImmediateModeInterface : ModuleRules
{
	public SlateImmediateModeInterface(ReadOnlyTargetRules Target) : base(Target)
	{
		PublicDependencyModuleNames.AddRange( 
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"SlateIM",
			}
		);
	}
}
