#pragma once

#include <Subsystems/GameInstanceSubsystem.h>

#include <HAL/IConsoleManager.h>

#include "SimiToolbar.h"

#include "SimiSubsystem.generated.h"

UCLASS()
class USimiSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	// ~Begin UGameInstanceSubsystem interface
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	// ~End UGameInstanceSubsystem interface

	void ToggleWidget();

	TUniquePtr<FSimiToolbar> ToolbarInstance;
	IConsoleCommand* ToggleCommand;
};
