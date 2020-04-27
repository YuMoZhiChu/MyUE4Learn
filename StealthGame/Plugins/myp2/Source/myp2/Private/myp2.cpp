// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "myp2.h"
#include "myp2Style.h"
#include "myp2Commands.h"
#include "Misc/MessageDialog.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"

#include "LevelEditor.h"

static const FName myp2TabName("myp2");

#define LOCTEXT_NAMESPACE "Fmyp2Module"

void Fmyp2Module::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	Fmyp2Style::Initialize();
	Fmyp2Style::ReloadTextures();

	Fmyp2Commands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		Fmyp2Commands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &Fmyp2Module::PluginButtonClicked),
		FCanExecuteAction());
		
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	
	{
		TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
		MenuExtender->AddMenuExtension("WindowLayout", EExtensionHook::After, PluginCommands, FMenuExtensionDelegate::CreateRaw(this, &Fmyp2Module::AddMenuExtension));

		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	}
	
	{
		TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
		ToolbarExtender->AddToolBarExtension("Settings", EExtensionHook::After, PluginCommands, FToolBarExtensionDelegate::CreateRaw(this, &Fmyp2Module::AddToolbarExtension));
		
		LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
	}
}

void Fmyp2Module::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	Fmyp2Style::Shutdown();

	Fmyp2Commands::Unregister();
}

void Fmyp2Module::PluginButtonClicked()
{
	// Put your "OnButtonClicked" stuff here
	FText DialogText = FText::Format(
							LOCTEXT("PluginButtonDialogText", "Add code to {0} in {1} to override this button's actions"),
							FText::FromString(TEXT("Fmyp2Module::PluginButtonClicked()")),
							FText::FromString(TEXT("myp2.cpp"))
					   );
	FMessageDialog::Open(EAppMsgType::Ok, DialogText);
}

void Fmyp2Module::AddMenuExtension(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(Fmyp2Commands::Get().PluginAction);
}

void Fmyp2Module::AddToolbarExtension(FToolBarBuilder& Builder)
{
	Builder.AddToolBarButton(Fmyp2Commands::Get().PluginAction);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(Fmyp2Module, myp2)