#include "SimiSelfRegisteringToolbarButton.h"

#include "SimiModule.h"
#include "SlateIMWidgetBase.h"

FSimiSelfRegisteringToolbarButton::FSimiSelfRegisteringToolbarButton(FSlateIMWidgetBase* Widget, const FString& Category, const FString& Button)
{
	FSimiModule::Get().RegisterMenuEntry({Category, Button, FSimpleDelegate::CreateLambda([Widget]()
	{
		Widget->ToggleWidget();
	})});
}

FSimiSelfRegisteringToolbarButton::~FSimiSelfRegisteringToolbarButton()
{
}
