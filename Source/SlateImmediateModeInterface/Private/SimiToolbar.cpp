#include "SimiToolbar.h"

#include <Engine.h>
#include <Widgets/Layout/SBox.h>
#include <SlateIM.h>

#include "SimiHelpers.h"
#include "SimiModule.h"

FSimiToolbar::FSimiToolbar()
	: FSlateIMExposedBase(TEXT("SimiToolbar"))
	, ExposedContent(MakeShared<SBox>())
{
	OnExposedWidgetChanged.AddRaw(this, &FSimiToolbar::OnExposedWidgetUpdated);
}

FSimiToolbar::~FSimiToolbar()
{
	OnExposedWidgetChanged.RemoveAll(this);
}

void FSimiToolbar::DrawContent(float DeltaTime)
{
	SCOPED_NAMED_EVENT_TEXT("FSimiToolbar::DrawContent", FColorList::Goldenrod);

	SlateIM::BeginBorder(FAppStyle::GetBrush("ToolPanel.GroupBorder"), Orient_Vertical, false, FMargin(0));

	SlateIM::MinHeight(24.f);
	SlateIM::MaxHeight(24.f);

	SlateIM::HAlign(HAlign_Fill);
	SlateIM::BeginHorizontalStack();
	{
		SlateIM::BeginMenuBar();
		FSimiModule::Get().DrawMenuEntries(DeltaTime);
		SlateIM::EndMenuBar();

		// NOTE: Empty HorizontalStack to fill the space between left and right widgets
		SlateIM::Fill();
		SlateIM::BeginHorizontalStack();
		SlateIM::EndHorizontalStack();

		FSimiModule::Get().DrawMenuWidgets(DeltaTime);
	}
	SlateIM::EndHorizontalStack();

	SlateIM::EndBorder();
}

void FSimiToolbar::EnableWidget()
{
	FSlateIMExposedBase::EnableWidget();

	LayoutWidget = SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			ExposedContent.ToSharedRef()
		];

	SimiHelpers::AddOverlayWidget(LayoutWidget.ToSharedRef());
}

void FSimiToolbar::DisableWidget()
{
	FSlateIMExposedBase::DisableWidget();

	if (LayoutWidget.IsValid())
	{
		SimiHelpers::RemoveOverlayWidget(LayoutWidget.ToSharedRef());
		LayoutWidget.Reset();
	}
}

void FSimiToolbar::OnExposedWidgetUpdated(TSharedRef<SWidget> NewWidget)
{
	ExposedContent->SetContent(NewWidget);
}
