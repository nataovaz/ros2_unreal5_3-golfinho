using UnrealBuildTool;
using System.Collections.Generic;

public class Campus_ItabiraEditorTarget : TargetRules
{
    public Campus_ItabiraEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.V4;

        ExtraModuleNames.AddRange(new string[] { "Campus_Itabira" });
        // Remova as linhas referentes a RTTI/exceções!
    }
}
