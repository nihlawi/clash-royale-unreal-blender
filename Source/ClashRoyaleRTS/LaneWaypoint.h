#include "Tower.h"

#include "BaseTroop.h"
#include "Kismet/GameplayStatics.h"

ATower::ATower()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ATower::BeginPlay()
{
    Super::BeginPlay();
    CurrentHealth = MaxHealth;
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
        Destroy();
        if (bIsKingTower)
        {
            FString Winner = (TeamName == TEXT("Blue")) ? TEXT("Red") : TEXT("Blue");
            UE_LOG(LogTemp, Warning, TEXT("King tower destroyed. Winner: %s"), *Winner);
        }
    }
}

void ATower::FireAtClosestEnemy()
{
    TArray<AActor*> AllActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), AllActors);

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
