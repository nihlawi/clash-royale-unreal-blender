#include "DeployGhost.h"

#include "Components/StaticMeshComponent.h"

ADeployGhost::ADeployGhost()
{
    PrimaryActorTick.bCanEverTick = true;

    GhostMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GhostMesh"));
    RootComponent = GhostMesh;
    GhostMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    GhostMesh->SetCastShadow(false);
}

void ADeployGhost::BeginPlay()
{
    Super::BeginPlay();
    HideGhost();
}

void ADeployGhost::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ADeployGhost::ShowGhostAtLocation(const FVector& Location, bool bValid)
{
    bIsVisible = true;
    bIsValidPlacement = bValid;
    SetActorLocation(Location + SpawnOffset);

    if (GhostMesh)
    {
        GhostMesh->SetVisibility(true);
        GhostMesh->SetMaterial(0, nullptr);
        GhostMesh->SetRenderCustomDepth(true);
        GhostMesh->SetCustomDepthStencilValue(bValid ? 1 : 2);
    }
}

void ADeployGhost::HideGhost()
{
    bIsVisible = false;
    if (GhostMesh)
    {
        GhostMesh->SetVisibility(false);
    }
}
