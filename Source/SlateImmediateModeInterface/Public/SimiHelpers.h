#pragma once

#include <CoreMinimal.h>

class SWidget;

namespace SimiHelpers
{
	void AddOverlayWidget(TSharedRef<SWidget> InWidget);
	void RemoveOverlayWidget(TSharedRef<SWidget> InWidget);
}
