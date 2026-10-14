#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseTroop.generated.h"

class ATower;

UENUM(BlueprintType)
enum class ETroopState : uint8
{
    Idle,
    Move,
    Attack,
    Die
};

UCLASS()
class CLASHROYALERTS_API ABaseTroop : public AActor
{
    GENERATED_BODY()

public:
    ABaseTroop();

    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float MaxHealth = 100.f;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stats")
    float CurrentHealth = 100.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float MoveSpeed = 120.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float AttackRange = 180.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float Damage = 25.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float AttackCooldown = 1.2f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    FString TeamName = TEXT("Blue");

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
    ETroopState CurrentState = ETroopState::Idle;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
    AActor* CurrentTarget = nullptr;

    UFUNCTION(BlueprintCallable, Category = "Combat")
    void TakeDamage(float Amount);

    UFUNCTION(BlueprintCallable, Category = "Combat")
    virtual void AttackTarget();

protected:
    float AttackTimer = 0.f;
    FVector MoveDirection = FVector::ZeroVector;

    void MoveTowardsEnemyLane(float DeltaTime);
    bool FindClosestEnemyTarget();
    void Die();
};
