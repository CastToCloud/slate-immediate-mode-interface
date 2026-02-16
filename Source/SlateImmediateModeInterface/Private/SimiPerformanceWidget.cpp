#include "SimiPerformanceWidget.h"

#include <SlateIM.h>

extern ENGINE_API float GAverageFPS;

void FSimiPerformanceWidget::Draw(float DeltaTime)
{
	TimeSinceLastUpdate += DeltaTime;

	LastFrameRates.Add(GAverageFPS);

	if (TimeSinceLastUpdate > 0.5f)
	{
		float Sum = 0.0f;
		for (float Fps : LastFrameRates)
		{
			Sum += Fps;
		}

		const float AverageFps = Sum / LastFrameRates.Num();
		const float AverageMs = AverageFps > 0.0f ? (1000.0f / AverageFps) : 0.0f;

		FpsText = FString::Printf(TEXT("%.0ffps"), AverageFps);
		TimeText = FString::Printf(TEXT("%.3fms"), AverageMs);

		TimeSinceLastUpdate = 0;
	}

	SlateIM::Text(FpsText);
	SlateIM::Text(TEXT("|"));
	SlateIM::Text(TimeText);
}
