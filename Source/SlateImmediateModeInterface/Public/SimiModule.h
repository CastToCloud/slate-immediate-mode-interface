#pragma once

#include <Modules/ModuleManager.h>

#include "Examples/SimiPerformanceGraph.h"

#ifndef WITH_SIMI_EXAMPLES
#define WITH_SIMI_EXAMPLES 1
#endif

#if WITH_SIMI_EXAMPLES
#include "Examples/SimiPerformanceGraph.h"
#endif

class FSimiExtraWidget : public FVirtualDestructor
{
public:
	virtual void Draw(float DeltaTime) = 0;
};

struct FSimiMenuEntryInfo
{
	FString Category;
	FString Button;
	FSimpleDelegate OnClick;
};

struct FSimiMenuWidgetInfo
{
	TSharedRef<FSimiExtraWidget> Widget;
	int32 Priority;
};

class FSimiModule : public IModuleInterface
{
public:
	static FSimiModule& Get();

	void RegisterMenuEntry(FSimiMenuEntryInfo EntryInfo);
	void RegisterMenuWidget(FSimiMenuWidgetInfo WidgetInfo);

	void DrawMenuEntries(float DeltaTime);
	void DrawMenuWidgets(float DeltaTime);

private:
	// ~Begin IModuleInterface interface
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	// ~End IModuleInterface interface

	TArray<FSimiMenuEntryInfo> Entries;
	TArray<FSimiMenuWidgetInfo> Widgets;

#if WITH_SIMI_EXAMPLES
	TUniquePtr<FSimiPerformanceGraph> ExamplePerformanceGraph;
#endif
};
