#include "RTSMatchManager.h"
#include "Kismet/GameplayStatics.h"
#include "HUDManager.h"

void ARTSMatchManager::BeginPlay()
{
    Super::BeginPlay();
    StartMatch();
}

void ARTSMatchManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (bMatchFinished) return;

    CurrentTimeRemaining -= DeltaTime;
    TickElixir(DeltaTime);

    // update HUD if present
    TArray<AActor*> Found;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AHUDManager::StaticClass(), Found);
    if (Found.Num() > 0)
    {
        AHUDManager* HM = Cast<AHUDManager>(Found[0]);
        if (HM)
        {
            HM->UpdateElixir(CurrentBlueElixir, MaxElixir);
            HM->UpdateTimer(CurrentTimeRemaining);
            HM->UpdateCrowns(BlueCrowns, RedCrowns);
        }
    }

    if (CurrentTimeRemaining <= 0.f)
    {
        ResolveTimeEnd();
    }
}
