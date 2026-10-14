#include "RTSMatchManager.h"

ARTSMatchManager::ARTSMatchManager()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ARTSMatchManager::BeginPlay()
{
    Super::BeginPlay();
    StartMatch();
}

void ARTSMatchManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (bMatchFinished)
    {
        return;
    }

    CurrentTimeRemaining -= DeltaTime;
    TickElixir(DeltaTime);

    if (CurrentTimeRemaining <= 0.f)
    {
        ResolveTimeEnd();
    }
}

void ARTSMatchManager::StartMatch()
{
    CurrentTimeRemaining = MatchDuration;
    CurrentBlueElixir = 5;
    CurrentRedElixir = 5;
    BlueCrowns = 0;
    RedCrowns = 0;
    bMatchFinished = false;
    WinnerText = TEXT("In Progress");
}

void ARTSMatchManager::TickElixir(float DeltaTime)
{
    static float BlueAccumulator = 0.f;
    static float RedAccumulator = 0.f;

    BlueAccumulator += DeltaTime;
    RedAccumulator += DeltaTime;

    float BlueTick = (CurrentTimeRemaining <= 60.f) ? 1.4f : 2.8f;
    float RedTick = (CurrentTimeRemaining <= 60.f) ? 1.4f : 2.8f;

    if (BlueAccumulator >= BlueTick)
    {
        BlueAccumulator = 0.f;
        GenerateBlueElixir();
    }

    if (RedAccumulator >= RedTick)
    {
        RedAccumulator = 0.f;
        GenerateRedElixir();
    }
}

void ARTSMatchManager::GenerateBlueElixir()
{
    if (bMatchFinished)
    {
        return;
    }
    CurrentBlueElixir = FMath::Min(CurrentBlueElixir + 1, MaxElixir);
}

void ARTSMatchManager::GenerateRedElixir()
{
    if (bMatchFinished)
    {
        return;
    }
    CurrentRedElixir = FMath::Min(CurrentRedElixir + 1, MaxElixir);
}

bool ARTSMatchManager::TrySpendBlueElixir(int32 Cost)
{
    if (Cost <= 0)
    {
        return false;
    }

    if (CurrentBlueElixir < Cost)
    {
        return false;
    }

    CurrentBlueElixir -= Cost;
    return true;
}

bool ARTSMatchManager::TrySpendRedElixir(int32 Cost)
{
    if (Cost <= 0)
    {
        return false;
    }

    if (CurrentRedElixir < Cost)
    {
        return false;
    }

    CurrentRedElixir -= Cost;
    return true;
}

void ARTSMatchManager::RegisterBlueTowerDestroyed()
{
    RedCrowns += 1;
    if (RedCrowns >= 3)
    {
        FinishMatch(TEXT("Red"));
    }
}

void ARTSMatchManager::RegisterRedTowerDestroyed()
{
    BlueCrowns += 1;
    if (BlueCrowns >= 3)
    {
        FinishMatch(TEXT("Blue"));
    }
}

void ARTSMatchManager::ResolveTimeEnd()
{
    if (BlueCrowns > RedCrowns)
    {
        FinishMatch(TEXT("Blue"));
    }
    else if (RedCrowns > BlueCrowns)
    {
        FinishMatch(TEXT("Red"));
    }
    else
    {
        FinishMatch(TEXT("Draw"));
    }
}

void ARTSMatchManager::FinishMatch(const FString& Winner)
{
    if (bMatchFinished)
    {
        return;
    }

    bMatchFinished = true;
    WinnerText = Winner;
    UE_LOG(LogTemp, Warning, TEXT("Match finished. Winner: %s"), *Winner);
}
