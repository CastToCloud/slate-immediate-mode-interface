#include "SimiHelpers.h"

#include <Framework/Application/SlateApplication.h>
#include <Widgets/SViewport.h>

namespace
{
	constexpr int32 SimiZOrder = 98765;
}

void SimiHelpers::AddOverlayWidget(TSharedRef<SWidget> InWidget)
{
	if (GIsEditor)
	{
		TSharedPtr<SViewport> PIEViewport = FSlateApplication::Get().GetGameViewport();
		TSharedPtr<SOverlay> PIEOverlay = StaticCastSharedPtr<SOverlay>(PIEViewport->GetContent());
		PIEOverlay->AddSlot(SimiZOrder)
		[
			InWidget
		];
	}
	else
	{
		TSharedPtr<SWindow> ActiveWindow = FSlateApplication::Get().GetActiveTopLevelWindow();
		ActiveWindow->AddOverlaySlot(SimiZOrder)
		[
			InWidget
		];
	}
}

void SimiHelpers::RemoveOverlayWidget(TSharedRef<SWidget> InWidget)
{
	if (GIsEditor)
	{
		TSharedPtr<SViewport> PIEViewport = FSlateApplication::Get().GetGameViewport();
		TSharedPtr<SOverlay> PIEOverlay = StaticCastSharedPtr<SOverlay>(PIEViewport->GetContent());
		PIEOverlay->RemoveSlot(InWidget);
	}
	else
	{
		TSharedPtr<SWindow> ActiveWindow = FSlateApplication::Get().GetActiveTopLevelWindow();
		ActiveWindow->RemoveOverlaySlot(InWidget);
	}
}
