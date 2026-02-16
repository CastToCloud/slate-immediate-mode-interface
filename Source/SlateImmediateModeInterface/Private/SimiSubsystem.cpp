#include "SimiSubsystem.h"

#include <Engine/GameInstance.h>

void USimiSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	ToolbarInstance = MakeUnique<FSimiToolbar>();

	FConsoleCommandDelegate ExecuteToggle = FConsoleCommandDelegate::CreateUObject(this, &ThisClass::ToggleWidget);
	ToggleCommand = IConsoleManager::Get().RegisterConsoleCommand(TEXT("Simi.Toolbar"), TEXT("Toggles the SIMI toolbar visibility"), ExecuteToggle);
}

void USimiSubsystem::Deinitialize()
{
	Super::Deinitialize();

	IConsoleManager::Get().UnregisterConsoleObject(ToggleCommand);

	ToolbarInstance.Reset();
}

void USimiSubsystem::ToggleWidget()
{
	if (ToolbarInstance)
	{
		ToolbarInstance->ToggleWidget();
	}
}
