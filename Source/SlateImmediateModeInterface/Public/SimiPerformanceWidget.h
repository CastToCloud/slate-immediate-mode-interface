#pragma once

#include "SimiModule.h"

class FSimiPerformanceWidget : public FSimiExtraWidget
{
	// ~Begin FSimiExtraWidget interface
	virtual void Draw(float DeltaTime) override;
	// ~End FSimiExtraWidget interface

	double TimeSinceLastUpdate = 0.0;
	TArray<int32> LastFrameRates;

	FString TimeText = TEXT("-");
	FString FpsText = TEXT("-");
};
