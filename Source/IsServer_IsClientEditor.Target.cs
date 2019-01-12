// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class IsServer_IsClientEditorTarget : TargetRules
{
	public IsServer_IsClientEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "IsServer_IsClient" } );
	}
}
