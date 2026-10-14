#include "DeckWidget.h"

#include "RTSPlayerController.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

bool UDeckWidget::DeployCardFromSlot(int32 SlotIndex)
{
    APlayerController* PC = GetOwningPlayer();
    if (!PC) return false;

    ARTSPlayerController* RTS = Cast<ARTSPlayerController>(PC);
    if (!RTS) return false;

    // Get current mouse/touch position on screen. For touch platforms, UMG will usually pass touch coords to a handler in BP and call this function with explicit coords.
    float X = 0.f, Y = 0.f;
    bool bHaveMouse = PC->GetMousePosition(X, Y);
    FVector2D ScreenPos = bHaveMouse ? FVector2D(X, Y) : FVector2D(PC->ViewportClient->Viewport->GetSizeXY());

    return RTS->TryDeployCardAtScreenLocation(SlotIndex, ScreenPos);
}
