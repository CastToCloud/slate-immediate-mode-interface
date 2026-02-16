#pragma once

#include <CoreMinimal.h>

class FSlateIMWidgetBase;

class FSimiSelfRegisteringToolbarButton
{
public:
	FSimiSelfRegisteringToolbarButton(FSlateIMWidgetBase* Widget, const FString& Category, const FString& Button);
	virtual ~FSimiSelfRegisteringToolbarButton();
};
