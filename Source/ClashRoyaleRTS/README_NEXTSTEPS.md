#include "Projectile.h"

#include "BaseTroop.h"
#include "Kismet/GameplayStatics.h"

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

    if (FVector::DistSquared(GetActorLocation(), TargetActor->GetActorLocation()) < FMath::Square(60.f))
    {
        // Splash damage
        TArray<FOverlapResult> Overlaps;
        FCollisionShape Sphere = FCollisionShape::MakeSphere(SplashRadius);
        GetWorld()->OverlapMultiByChannel(Overlaps, GetActorLocation(), FQuat::Identity, ECC_Pawn, Sphere);
        for (auto& R : Overlaps)
        {
            AActor* Other = R.GetActor();
            if (!Other) continue;
            ABaseTroop* Troop = Cast<ABaseTroop>(Other);
            ATower* Tower = Cast<ATower>(Other);
            if (Troop && Troop->TeamName != TeamName)
            {
                Troop->TakeDamage(Damage);
            }
            if (Tower && Tower->TeamName != TeamName)
            {
                Tower->TakeDamage(Damage);
            }
        }

        Destroy();
    }
}
