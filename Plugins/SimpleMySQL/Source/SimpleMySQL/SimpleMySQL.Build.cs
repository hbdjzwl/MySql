// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;
public class SimpleMySQL : ModuleRules
{
    public string ProjectDirectory
    {
        get
        {
            return Path.GetFullPath(Path.Combine(ModuleDirectory,"../../../../"));  //��Ŀ·��
        }
    }

    private void CopyToProjectBinaries(string FilePathName, ReadOnlyTargetRules Target)
    {
        string BineriesDirectory = Path.Combine(ProjectDirectory, "Binaries", Target.Platform.ToString());
        string Filename = Path.GetFileName(FilePathName);

        if (!Directory.Exists(BineriesDirectory))
        {
            Directory.CreateDirectory(BineriesDirectory);
        }

        string ProjectFileFullName = Path.Combine(BineriesDirectory, Filename);
        if (!File.Exists(ProjectFileFullName))
        {
            File.Copy(FilePathName, ProjectFileFullName, true);
        }

        RuntimeDependencies.Add(ProjectFileFullName);
    }

    public SimpleMySQL(ReadOnlyTargetRules Target) : base(Target)
	{
        //https://blog.csdn.net/u010385624/article/details/102638449
        //������������ʱ���п��ܳ���Ԥ������û�ж����������ڿ��ͷ�ļ���ʹ��Ԥ����������ĳЩ�ж�ʱ���ᱨ���������
        bEnableUndefinedIdentifierWarnings = false;

        PublicDefinitions.Add("NTDDI_WIN7SP1"); //����windows�汾 

        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        string PluginsDirectory = Path.GetFullPath(Path.Combine(ModuleDirectory, "..", ".."));//·��
        string SQLLibDirectory = Path.Combine(PluginsDirectory, "MySQL"); //MySQL·��
        string PlatformString = (Target.Platform == UnrealTargetPlatform.Win64) ? "x64" : "x86";

        string MysqlPath = Path.Combine(SQLLibDirectory, PlatformString);

        PublicIncludePaths.Add(MysqlPath);

        RuntimeDependencies.Add(Path.Combine(MysqlPath, "libmysql.dll"));   //��̬����
        PublicAdditionalLibraries.Add(Path.Combine(MysqlPath, "libmysql.lib")); //��̬����

        CopyToProjectBinaries(Path.Combine(MysqlPath, "libmysql.dll"), Target);
        CopyToProjectBinaries(Path.Combine(MysqlPath, "libmysql.lib"), Target);


        PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
