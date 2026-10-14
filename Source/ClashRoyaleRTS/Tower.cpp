#include "Tower.h"

#include "BaseTroop.h"
#include "Kismet/GameplayStatics.h"
#include "TowerManager.h"
#include "ClashRoyaleRTSGameModeBase.h"

ATower::ATower()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ATower::BeginPlay()
{
    Super::BeginPlay();
    CurrentHealth = MaxHealth;

    // Register with TowerManager if present in the level
    TArray<AActor*> Found;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATowerManager::StaticClass(), Found);
    if (Found.Num() > 0)
    {
        ATowerManager* Manager = Cast<ATowerManager>(Found[0]);
        if (Manager)
        {
            Manager->RegisterTower(this);
        }
    }
}

void ATower::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FireAccumulator += DeltaTime;
    if (FireAccumulator >= FireRate)
    {
        FireAccumulator = 0.f;
        FireAtClosestEnemy();
    }
}

void ATower::TakeDamage(float Amount)
{
    CurrentHealth -= Amount;
    if (CurrentHealth <= 0.f)
    {
        // Notify tower manager and game mode
        TArray<AActor*> Found;
        UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATowerManager::StaticClass(), Found);
        if (Found.Num() > 0)
        {
            ATowerManager* Manager = Cast<ATowerManager>(Found[0]);
            if (Manager)
            {
                Manager->NotifyTowerDestroyed(this);
            }
        }

        // If this is the king tower, end the match immediately
        if (bIsKingTower)
        {
            AClashRoyaleRTSGameModeBase* GM = Cast<AClashRoyaleRTSGameModeBase>(UGameplayStatics::GetGameMode(this));
            if (GM)
            {
                FString Winner = (TeamName == TEXT("Blue")) ? TEXT("Red") : TEXT("Blue");
                GM->EndMatch(Winner);
            }
        }

        Destroy();
    }
}

void ATower::FireAtClosestEnemy()
{
    TArray<AActor*> AllActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABaseTroop::StaticClass(), AllActors);

    AActor* BestTarget = nullptr;
    float BestDistance = TNumericLimits<float>::Max();

    for (AActor* TestActor : AllActors)
    {
        if (!TestActor || TestActor == this)
        {
            continue;
        }

        ABaseTroop* Troop = Cast<ABaseTroop>(TestActor);
        if (!Troop)
        {
            continue;
        }

        if (Troop->TeamName == TeamName)
        {
            continue;
        }

        float Dist = FVector::Dist(TestActor->GetActorLocation(), GetActorLocation());
        if (Dist <= FireRange && Dist < BestDistance)
        {
            BestDistance = Dist;
            BestTarget = TestActor;
        }
    }

    if (BestTarget)
    {
        ABaseTroop* Troop = Cast<ABaseTroop>(BestTarget);
        if (Troop)
        {
            Troop->TakeDamage(Damage);
        }
    }
}
