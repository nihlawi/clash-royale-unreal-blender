#include "BaseTroop.h"

#include "Tower.h"
#include "Kismet/KismetMathLibrary.h"

ABaseTroop::ABaseTroop()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ABaseTroop::BeginPlay()
{
    Super::BeginPlay();
    CurrentHealth = MaxHealth;
    CurrentState = ETroopState::Move;
}

void ABaseTroop::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (CurrentHealth <= 0.f)
    {
        Die();
        return;
    }

    if (CurrentState == ETroopState::Move)
    {
        MoveTowardsEnemyLane(DeltaTime);
        FindClosestEnemyTarget();
    }
    else if (CurrentState == ETroopState::Attack)
    {
        if (CurrentTarget == nullptr)
        {
            CurrentState = ETroopState::Move;
            return;
        }

        AttackTimer -= DeltaTime;
        if (AttackTimer <= 0.f)
        {
            AttackTarget();
            AttackTimer = AttackCooldown;
        }
    }
}

void ABaseTroop::MoveTowardsEnemyLane(float DeltaTime)
{
    FVector TargetLocation = GetActorLocation();
    if (TeamName == TEXT("Blue"))
    {
        TargetLocation.X += 1500.f;
    }
    else
    {
        TargetLocation.X -= 1500.f;
    }

    FVector Direction = (TargetLocation - GetActorLocation()).GetSafeNormal();
    if (!Direction.IsNearlyZero())
    {
        SetActorLocation(GetActorLocation() + Direction * MoveSpeed * DeltaTime);
    }
}

bool ABaseTroop::FindClosestEnemyTarget()
{
    TArray<AActor*> Candidates;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATower::StaticClass(), Candidates);

    float BestDistance = TNumericLimits<float>::Max();
    AActor* BestTarget = nullptr;

    for (AActor* Candidate : Candidates)
    {
        if (!Candidate)
        {
            continue;
        }

        ATower* CandidateTower = Cast<ATower>(Candidate);
        if (!CandidateTower)
        {
            continue;
        }

        if (CandidateTower->TeamName == TeamName)
        {
            continue;
        }

        float DistSq = FVector::DistSquared(GetActorLocation(), Candidate->GetActorLocation());
        if (DistSq < BestDistance)
        {
            BestDistance = DistSq;
            BestTarget = Candidate;
        }
    }

    if (BestTarget)
    {
        CurrentTarget = BestTarget;
        CurrentState = ETroopState::Attack;
        AttackTimer = 0.f;
        return true;
    }

    return false;
}

void ABaseTroop::AttackTarget()
{
    if (!CurrentTarget)
    {
        CurrentState = ETroopState::Move;
        return;
    }

    float Distance = FVector::Dist(GetActorLocation(), CurrentTarget->GetActorLocation());
    if (Distance > AttackRange)
    {
        CurrentState = ETroopState::Move;
        return;
    }

    ATower* TowerTarget = Cast<ATower>(CurrentTarget);
    if (TowerTarget)
    {
        TowerTarget->TakeDamage(Damage);
    }
}

void ABaseTroop::TakeDamage(float Amount)
{
    CurrentHealth -= Amount;
    if (CurrentHealth <= 0.f)
    {
        Die();
    }
}

void ABaseTroop::Die()
{
    CurrentState = ETroopState::Die;
    Destroy();
}
