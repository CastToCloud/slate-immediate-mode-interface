#include "Examples/SimiPerformanceGraph.h"

#include <SlateIM.h>

extern ENGINE_API float GAverageFPS;

FSimiPerformanceGraph::FSimiPerformanceGraph()
	: FSlateIMWindowBase(TEXT("Example Performance Graph"), FVector2f(1000, 500), true, TEXT("Simi.Examples.PerformanceGraph"), TEXT("Opens a window that contains performance graph"))
	, FSimiSelfRegisteringToolbarButton(this, "Examples", "PerformanceGraph")
{
}

FSimiPerformanceGraph::~FSimiPerformanceGraph()
{
}

void FSimiPerformanceGraph::DrawWindow(float DeltaTime)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(FSimiToolbar::DrawFPSGraph)

	const int NumPoints = 500;

	if (FrameRateValues.Num() >= NumPoints)
	{
		FrameRateValues.PopFront();
	}
	FrameRateValues.Emplace(GFrameCounter, GAverageFPS);

	SlateIM::BeginHorizontalStack();

	SlateIM::Fill();
	SlateIM::MinHeight(200.f);

	SlateIM::BeginGraph();
	SlateIM::GraphLine(FrameRateValues.Compact(), FColor::White, 1.f, FDoubleRange(GFrameCounter - NumPoints, GFrameCounter), FDoubleRange(0, 100));
	SlateIM::EndGraph();

	SlateIM::MinWidth(50.f);
	SlateIM::MaxWidth(50.f);
	SlateIM::BeginVerticalStack();
	SlateIM::Fill();
	SlateIM::VAlign(VAlign_Center);
	SlateIM::Text(FString::Printf(TEXT("%0.3lf"), FrameRateValues.Last().Y), FColor::White);
	SlateIM::Fill();
	SlateIM::EndVerticalStack();

	SlateIM::EndHorizontalStack();
}
