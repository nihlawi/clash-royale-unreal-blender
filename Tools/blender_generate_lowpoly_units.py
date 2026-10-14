#include "Projectile.h"

#include "BaseTroop.h"

AProjectile::AProjectile()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AProjectile::BeginPlay()
{
    Super::BeginPlay();
}

void AProjectile::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    LifeTime -= DeltaTime;
    if (LifeTime <= 0.f)
    {
        Destroy();
        return;
    }

    if (!TargetActor)
    {
        Destroy();
        return;
    }

    FVector Direction = (TargetActor->GetActorLocation() - GetActorLocation()).GetSafeNormal();
    SetActorLocation(GetActorLocation() + Direction * ProjectileSpeed * DeltaTime);

    if (FVector::DistSquared(GetActorLocation(), TargetActor->GetActorLocation()) < 150.f)
    {
        ABaseTroop* Troop = Cast<ABaseTroop>(TargetActor);
        if (Troop)
        {
            Troop->TakeDamage(Damage);
        }
        Destroy();
    }
}
