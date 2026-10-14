#include "ArenaBuilder.h"

#include "Tower.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

AArenaBuilder::AArenaBuilder()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AArenaBuilder::BeginPlay()
{
    Super::BeginPlay();
    BuildArena();
    SpawnDefaultTowers();
    CreateLaneWaypoints();
}

void AArenaBuilder::BuildArena()
{
    // Ground & river surfaces are created as simple static meshes in the editor.
    // This function records the intended arena geometry and spawns a default footing for the map.
    FVector Center = GetActorLocation();

    // Create a flat arena base using a simple large cube
    UWorld* World = GetWorld();
    if (!World) return;

    FActorSpawnParameters Params;
    Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

    AActor* ArenaBase = World->SpawnActor<AActor>(AActor::StaticClass(), Center, FRotator::ZeroRotator, Params);
    if (ArenaBase)
    {
        UStaticMeshComponent* Mesh = NewObject<UStaticMeshComponent>(ArenaBase);
        Mesh->SetStaticMesh(LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cube.Cube")));
        Mesh->SetRelativeScale3D(FVector(ArenaLength / 100.f, 1100.f / 100.f, 20.f / 100.f));
        Mesh->SetRelativeLocation(FVector(0.f, 0.f, -10.f));
        Mesh->RegisterComponent();
        ArenaBase->AddInstanceComponent(Mesh);
    }

    // Create the river strip between the lanes
    AActor* River = World->SpawnActor<AActor>(AActor::StaticClass(), Center + FVector(0.f, 0.f, 2.f), FRotator::ZeroRotator, Params);
    if (River)
    {
        UStaticMeshComponent* RiverMesh = NewObject<UStaticMeshComponent>(River);
        RiverMesh->SetStaticMesh(LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cube.Cube")));
        RiverMesh->SetRelativeScale3D(FVector(2500.f / 100.f, RiverWidth / 100.f, 12.f / 100.f));
        RiverMesh->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
        RiverMesh->RegisterComponent();
        River->AddInstanceComponent(RiverMesh);
    }
}

void AArenaBuilder::SpawnDefaultTowers()
{
    UWorld* World = GetWorld();
    if (!World) return;

    FActorSpawnParameters Params;
    Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

    // Player-side towers
    FVector BlueBase = GetActorLocation() + FVector(-1000.f, 0.f, 80.f);
    FVector RedBase = GetActorLocation() + FVector(1000.f, 0.f, 80.f);

    // Blue side
    World->SpawnActor<ATower>(ATower::StaticClass(), BlueBase + FVector(0.f, -250.f, 0.f), FRotator::ZeroRotator, Params);
    World->SpawnActor<ATower>(ATower::StaticClass(), BlueBase + FVector(0.f, 250.f, 0.f), FRotator::ZeroRotator, Params);
    ATower* KingBlue = World->SpawnActor<ATower>(ATower::StaticClass(), BlueBase, FRotator::ZeroRotator, Params);
    if (KingBlue)
    {
        KingBlue->bIsKingTower = true;
        KingBlue->TeamName = TEXT("Blue");
        KingBlue->MaxHealth = 2000.f;
        KingBlue->CurrentHealth = 2000.f;
    }

    // Red side
    World->SpawnActor<ATower>(ATower::StaticClass(), RedBase + FVector(0.f, -250.f, 0.f), FRotator::ZeroRotator, Params);
    World->SpawnActor<ATower>(ATower::StaticClass(), RedBase + FVector(0.f, 250.f, 0.f), FRotator::ZeroRotator, Params);
    ATower* KingRed = World->SpawnActor<ATower>(ATower::StaticClass(), RedBase, FRotator::ZeroRotator, Params);
    if (KingRed)
    {
        KingRed->bIsKingTower = true;
        KingRed->TeamName = TEXT("Red");
        KingRed->MaxHealth = 2000.f;
        KingRed->CurrentHealth = 2000.f;
    }
}

void AArenaBuilder::CreateLaneWaypoints()
{
    // Create simple waypoint locations along two lanes. This is intended to be used by the troop AI.
    BlueSpawnPoints.Empty();
    RedSpawnPoints.Empty();

    for (int32 i = 0; i < 6; ++i)
    {
        float T = float(i) / 5.f;
        BlueSpawnPoints.Add(GetActorLocation() + FVector(-1200.f + T * 2200.f, -200.f, 60.f));
        RedSpawnPoints.Add(GetActorLocation() + FVector(1200.f - T * 2200.f, 200.f, 60.f));
    }
}
