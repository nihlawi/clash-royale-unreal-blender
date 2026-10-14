#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class CLASHROYALERTS_API AProjectile : public AActor
{
    GENERATED_BODY()

public:
    AProjectile();

    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
    float ProjectileSpeed = 700.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
    float Damage = 25.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
    float SplashRadius = 150.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
    AActor* TargetActor = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
    FString TeamName = TEXT("Blue");

private:
    float LifeTime = 2.5f;
};
