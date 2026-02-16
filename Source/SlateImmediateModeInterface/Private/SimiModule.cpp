#include "SimiModule.h"

#include <SlateIM.h>

#include "SimiPerformanceWidget.h"

FSimiModule& FSimiModule::Get()
{
	return FModuleManager::LoadModuleChecked<FSimiModule>("SlateImmediateModeInterface");
}

void FSimiModule::RegisterMenuEntry(FSimiMenuEntryInfo EntryInfo)
{
	Entries.Add(EntryInfo);
}

void FSimiModule::RegisterMenuWidget(FSimiMenuWidgetInfo WidgetInfo)
{
	Widgets.Add(WidgetInfo);
}

void FSimiModule::DrawMenuEntries(float DeltaTime)
{
	TArray<FSimiMenuEntryInfo> SortedEntries = Entries;
	
	SortedEntries.Sort([](const FSimiMenuEntryInfo& A, const FSimiMenuEntryInfo& B)
	{
		if (A.Category != B.Category)
		{
			return A.Category < B.Category;
		}

		return A.Button < B.Button;
	});

	FString CurrentCategory;
	for (const auto& Entry : SortedEntries)
	{
		if (Entry.Category != CurrentCategory)
		{
			CurrentCategory = Entry.Category;
			SlateIM::AddMenuBarEntry(CurrentCategory);
		}
		if (SlateIM::AddMenuButton(Entry.Button))
		{
			Entry.OnClick.ExecuteIfBound();
		}
	}
}

void FSimiModule::DrawMenuWidgets(float DeltaTime)
{
	TArray<FSimiMenuWidgetInfo> SortedWidgets = Widgets;

	SortedWidgets.Sort([](const FSimiMenuWidgetInfo& A, FSimiMenuWidgetInfo B)
	{
		return A.Priority < B.Priority;
	});

	for (const auto& Widget : SortedWidgets)
	{
		Widget.Widget->Draw(DeltaTime);
	}
}

void FSimiModule::StartupModule()
{
	RegisterMenuWidget({MakeShared<FSimiPerformanceWidget>(), 999});

#if WITH_SIMI_EXAMPLES
	ExamplePerformanceGraph = MakeUnique<FSimiPerformanceGraph>();
#endif
}

void FSimiModule::ShutdownModule()
{
#if WITH_SIMI_EXAMPLES
	ExamplePerformanceGraph.Reset();
#endif
}

IMPLEMENT_MODULE(FSimiModule, SlateImmediateModeInterface)
