// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "myp2Commands.h"

#define LOCTEXT_NAMESPACE "Fmyp2Module"

void Fmyp2Commands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "myp2", "Execute myp2 action", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
