#include "ObjectPoolComponent.h"

#include "Engine/World.h"

UObjectPoolComponent::UObjectPoolComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UObjectPoolComponent::BeginPlay()
{
    Super::BeginPlay();
}

void UObjectPoolComponent::InitializePool(TSubclassOf<AActor> ActorClass, int32 InitialSize)
{
    if (!ActorClass) return;

    PooledClass = ActorClass;
    UWorld* World = GetWorld();
    if (!World) return;

    for (int32 i = 0; i < InitialSize; ++i)
    {
        FActorSpawnParameters Params;
        Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
        AActor* A = World->SpawnActor<AActor>(PooledClass, FVector::ZeroVector, FRotator::ZeroRotator, Params);
        if (A)
        {
            A->SetActorEnableCollision(false);
            A->SetActorHiddenInGame(true);
            Pool.Add(A);
        }
    }
}

AActor* UObjectPoolComponent::AcquireFromPool()
{
    for (int32 i = 0; i < Pool.Num(); ++i)
    {
        AActor* A = Pool[i];
        if (A && A->IsHidden())
        {
            A->SetActorHiddenInGame(false);
            A->SetActorEnableCollision(true);
            return A;
        }
    }

    if (bAutoExpand && PooledClass)
    {
        UWorld* World = GetWorld();
        if (!World) return nullptr;
        FActorSpawnParameters Params;
        Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
        AActor* A = World->SpawnActor<AActor>(PooledClass, FVector::ZeroVector, FRotator::ZeroRotator, Params);
        if (A)
        {
            Pool.Add(A);
            return A;
        }
    }

    return nullptr;
}

void UObjectPoolComponent::ReleaseToPool(AActor* Actor)
{
    if (!Actor) return;
    Actor->SetActorEnableCollision(false);
    Actor->SetActorHiddenInGame(true);
    // reposition off-screen
    Actor->SetActorLocation(FVector::ZeroVector);
}
