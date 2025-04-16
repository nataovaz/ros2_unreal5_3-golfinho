using UnrealBuildTool;
using System.Collections.Generic;

public class Campus_ItabiraTarget : TargetRules
{
    public Campus_ItabiraTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;
        DefaultBuildSettings = BuildSettingsVersion.V4;

        ExtraModuleNames.AddRange(new string[] { "Campus_Itabira" });
        // Remova as linhas referentes a RTTI/exceções!
    }
}
