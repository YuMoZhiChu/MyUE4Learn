// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "myp2Style.h"

class Fmyp2Commands : public TCommands<Fmyp2Commands>
{
public:

	Fmyp2Commands()
		: TCommands<Fmyp2Commands>(TEXT("myp2"), NSLOCTEXT("Contexts", "myp2", "myp2 Plugin"), NAME_None, Fmyp2Style::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
