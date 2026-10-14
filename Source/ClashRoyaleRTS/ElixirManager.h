#include "ClashRoyaleRTSGameModeBase.h"

AClashRoyaleRTSGameModeBase::AClashRoyaleRTSGameModeBase()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AClashRoyaleRTSGameModeBase::BeginPlay()
{
    Super::BeginPlay();
    StartGame();
}

void AClashRoyaleRTSGameModeBase::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    if (bMatchOver)
    {
        return;
    }

    TimeRemaining -= DeltaSeconds;
    if (TimeRemaining <= 0.f)
    {
        CheckForTimeWin();
        return;
    }

    ElixirAccumulator += DeltaSeconds;
    if (TimeRemaining <= 60.f)
    {
        CurrentElixirTick = FinalMinuteElixirTick;
    }
    else
    {
        CurrentElixirTick = BaseElixirTick;
    }

    if (ElixirAccumulator >= CurrentElixirTick)
    {
        ElixirAccumulator = 0.f;
        GenerateElixir();
    }
}

void AClashRoyaleRTSGameModeBase::StartGame()
{
    CurrentElixir = 5;
    TimeRemaining = MatchDuration;
    ElixirAccumulator = 0.f;
    CurrentElixirTick = BaseElixirTick;
    bMatchOver = false;
}

void AClashRoyaleRTSGameModeBase::GenerateElixir()
{
    if (bMatchOver)
    {
        return;
    }

    CurrentElixir = FMath::Min(CurrentElixir + 1, MaxElixir);
}

bool AClashRoyaleRTSGameModeBase::SpendElixir(int32 Cost)
{
    if (bMatchOver)
    {
        return false;
    }

    if (CurrentElixir < Cost)
    {
        return false;
    }

    CurrentElixir -= Cost;
    return true;
}

void AClashRoyaleRTSGameModeBase::EndMatch(const FString& WinningSide)
{
    bMatchOver = true;
    UE_LOG(LogTemp, Warning, TEXT("Match ended: %s"), *WinningSide);
}

void AClashRoyaleRTSGameModeBase::CheckForTimeWin()
{
    if (BlueCrownCount > RedCrownCount)
    {
        EndMatch(TEXT("Blue"));
    }
    else if (RedCrownCount > BlueCrownCount)
    {
        EndMatch(TEXT("Red"));
    }
    else
    {
        EndMatch(TEXT("Draw"));
    }
}

void AClashRoyaleRTSGameModeBase::RegisterTowerDestroyed(const FString& TeamName)
{
    if (TeamName == TEXT("Blue"))
    {
        RedCrownCount += 1;
    }
    else if (TeamName == TEXT("Red"))
    {
        BlueCrownCount += 1;
    }

    if (BlueCrownCount >= 3 || RedCrownCount >= 3)
    {
        EndMatch(BlueCrownCount >= 3 ? TEXT("Blue") : TEXT("Red"));
    }
}
