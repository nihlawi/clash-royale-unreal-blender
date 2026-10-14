#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyWaveManager.generated.h"

class ABaseTroop;

UCLASS()
class CLASHROYALERTS_API AEnemyWaveManager : public AActor
{
    GENERATED_BODY()

public:
    AEnemyWaveManager();

    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave")
    TArray<TSubclassOf<ABaseTroop>> UnitsToSpawn;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave")
    TArray<FVector> SpawnPoints;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave")
    float SpawnInterval = 5.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave")
    int32 MaxQueue = 6;

    UFUNCTION(BlueprintCallable, Category = "Wave")
    void QueueWave();

    UFUNCTION(BlueprintCallable, Category = "Wave")
    void SpawnNextEnemy();

private:
    float Accumulator = 0.f;
    int32 WaveIndex = 0;
};
