#include "CombatHUDWidget.h"

void UCombatHUDWidget::UpdateElixir(int32 Current, int32 Max)
{
    // This is intentionally kept lightweight; the UMG Blueprint widget will bind directly and extend this behavior.
    // If needed, this can be connected to text/image variables in a C++ widget subclass.
}

void UCombatHUDWidget::UpdateTimer(float TimeRemaining)
{
}

void UCombatHUDWidget::UpdateCrowns(int32 BlueCrowns, int32 RedCrowns)
{
}

void UCombatHUDWidget::UpdateDeck(TArray<FName> CardNames, FName NextPreview)
{
}

void UCombatHUDWidget::ShowMatchResult(const FString& ResultText)
{
}
