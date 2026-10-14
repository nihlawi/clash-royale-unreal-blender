#include "HUDManager.h"
#include "Blueprint/UserWidget.h"
#include "CombatHUDWidget.h"

AHUDManager::AHUDManager()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AHUDManager::BeginPlay()
{
    Super::BeginPlay();

    if (HUDWidgetClass)
    {
        UUserWidget* W = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);
        if (W)
        {
            W->AddToViewport();
            CombatHUD = Cast<UCombatHUDWidget>(W);
        }
    }
}

void AHUDManager::UpdateElixir(int32 Current, int32 Max)
{
    if (CombatHUD)
    {
        CombatHUD->UpdateElixir(Current, Max);
    }
}

void AHUDManager::UpdateTimer(float TimeRemaining)
{
    if (CombatHUD)
    {
        CombatHUD->UpdateTimer(TimeRemaining);
    }
}

void AHUDManager::UpdateCrowns(int32 BlueCrowns, int32 RedCrowns)
{
    if (CombatHUD)
    {
        CombatHUD->UpdateCrowns(BlueCrowns, RedCrowns);
    }
}
