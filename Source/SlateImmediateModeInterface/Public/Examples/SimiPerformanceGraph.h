#pragma once

#include <SlateIMWidgetBase.h>

#include "SimiSelfRegisteringToolbarButton.h"

#include <Containers/RingBuffer.h>

class FSimiPerformanceGraph : public FSlateIMWindowBase, public FSimiSelfRegisteringToolbarButton
{
public:
	FSimiPerformanceGraph();
	virtual ~FSimiPerformanceGraph() override;

	virtual void DrawWindow(float DeltaTime) override;

private:
	/**
	 * FPS from the last Frames
	 */
	TRingBuffer<FVector2D> FrameRateValues = { FVector2D(0, FMath::Sin(0.0)) };
};
