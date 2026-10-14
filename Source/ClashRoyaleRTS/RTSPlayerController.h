#include "RTSPlayerController.h"

#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "ClashRoyaleRTSGameModeBase.h"
#include "DeckComponent.h"
#include "Engine/Engine.h"

ARTSPlayerController::ARTSPlayerController()
{
    bShowMouseCursor = true;
    bEnableClickEvents = true;
    bEnableTouchEvents = true;
}

void ARTSPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    InputComponent->BindTouch(IE_Pressed, this, &ARTSPlayerController::OnTouchPressed);
    InputComponent->BindTouch(IE_Released, this, &ARTSPlayerController::OnTouchReleased);

    InputComponent->BindAction("DeployCard1", IE_Pressed, this, &ARTSPlayerController::OnDeployCard1);
}

void ARTSPlayerController::OnTouchPressed(const ETouchIndex::Type FingerIndex, const FVector Location)
{
    // store touch start for ghost spawn; in editor you may use mouse instead
}

void ARTSPlayerController::OnTouchReleased(const ETouchIndex::Type FingerIndex, const FVector Location)
{
    FVector2D ScreenPos(Location.X, Location.Y);
    // simple approach: we assume last selected slot is 0; in UMG you'd pass explicit slot index
    TryDeployCardAtScreenLocation(0, ScreenPos);
}

void ARTSPlayerController::OnDeployCard1()
{
    float X, Y;
    if (GetMousePosition(X, Y))
    {
        TryDeployCardAtScreenLocation(0, FVector2D(X, Y));
    }
}
