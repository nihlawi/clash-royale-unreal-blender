#include "ElixirManager.h"

UElixirManager::UElixirManager()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UElixirManager::BeginPlay()
{
    Super::BeginPlay();
    CurrentElixir = 5;
}

void UElixirManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    MatchTimeRemaining -= DeltaTime;
    ElixirAccumulator += DeltaTime;

    float TickRate = (MatchTimeRemaining <= 60.f) ? FinalMinuteTick : BaseTick;
    if (ElixirAccumulator >= TickRate)
    {
        ElixirAccumulator = 0.f;
        GenerateElixir();
    }
}

void UElixirManager::GenerateElixir()
{
    CurrentElixir = FMath::Min(CurrentElixir + 1, MaxElixir);
}

bool UElixirManager::SpendElixir(int32 Amount)
{
    if (CurrentElixir < Amount)
    {
        return false;
    }

    CurrentElixir -= Amount;
    return true;
}
