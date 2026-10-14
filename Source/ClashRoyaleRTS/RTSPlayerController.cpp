#include "ImprovedBaseTroop.h"

#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Tower.h"

AImprovedBaseTroop::AImprovedBaseTroop()
{
    TargetSearchInterval = 0.35f;
}

void AImprovedBaseTroop::BeginPlay()
{
    Super::BeginPlay();
}

void AImprovedBaseTroop::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    TargetSearchAccumulator += DeltaTime;
    if (TargetSearchAccumulator >= TargetSearchInterval && CurrentState == ETroopState::Move)
    {
        TargetSearchAccumulator = 0.f;
        FindClosestEnemyTarget();
    }
}

bool AImprovedBaseTroop::FindClosestEnemyTarget()
{
    // Prefer towers if this unit targets buildings
    UWorld* World = GetWorld();
    if (!World) return false;

    TArray<FOverlapResult> Overlaps;
    FVector MyLoc = GetActorLocation();
    FCollisionShape Sphere = FCollisionShape::MakeSphere(AttackRange * 4.0f);

    bool bHit = World->OverlapMultiByChannel(Overlaps, MyLoc, FQuat::Identity, ECC_Pawn, Sphere);

    AActor* Best = nullptr;
    float BestDist = FLT_MAX;

    if (bHit)
    {
        for (auto& R : Overlaps)
        {
            AActor* Other = R.GetActor();
            if (!Other || Other == this) continue;

            // Check team
            ABaseTroop* Troop = Cast<ABaseTroop>(Other);
            ATower* Tower = Cast<ATower>(Other);

            if (Troop && Troop->TeamName == TeamName) continue;
            if (Tower && Tower->TeamName == TeamName) continue;

            // If this unit prefers buildings, prefer towers
            if (targetsBuildingsOnly)
            {
                if (Tower)
                {
                    float d = FVector::DistSquared(MyLoc, Other->GetActorLocation());
                    if (d < BestDist)
                    {
                        BestDist = d; Best = Other;
                    }
                }
            }
            else
            {
                // not restricted: prefer closest enemy (troop or tower)
                float d = FVector::DistSquared(MyLoc, Other->GetActorLocation());
                if (d < BestDist)
                {
                    BestDist = d; Best = Other;
                }
            }
        }
    }

    if (!Best && targetsBuildingsOnly)
    {
        // fallback: search for towers further out
        TArray<AActor*> Towers;
        UGameplayStatics::GetAllActorsOfClass(World, ATower::StaticClass(), Towers);
        for (AActor* T : Towers)
        {
            ATower* TT = Cast<ATower>(T);
            if (!TT || TT->TeamName == TeamName) continue;
            float d = FVector::DistSquared(MyLoc, TT->GetActorLocation());
            if (d < BestDist)
            {
                BestDist = d; Best = TT;
            }
        }
    }

    if (Best)
    {
        CurrentTarget = Best;
        CurrentState = ETroopState::Attack;
        AttackTimer = 0.f;
        return true;
    }

    return false;
}
