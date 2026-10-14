#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tower.generated.h"

UCLASS()
class CLASHROYALERTS_API ATower : public AActor
{
    GENERATED_BODY()

public:
    ATower();

    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
    float MaxHealth = 1200.f;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tower")
    float CurrentHealth = 1200.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
    float FireRange = 350.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
    float FireRate = 1.2f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
    float Damage = 25.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
    FString TeamName = TEXT("Blue");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
    bool bIsKingTower = false;

    UFUNCTION(BlueprintCallable, Category = "Tower")
    void TakeDamage(float Amount);

    UFUNCTION(BlueprintCallable, Category = "Tower")
    void FireAtClosestEnemy();

private:
    float FireAccumulator = 0.f;
};
