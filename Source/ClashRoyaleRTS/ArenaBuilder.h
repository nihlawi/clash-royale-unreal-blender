#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ArenaBuilder.generated.h"

UCLASS()
class CLASHROYALERTS_API AArenaBuilder : public AActor
{
    GENERATED_BODY()

public:
    AArenaBuilder();

    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arena")
    float ArenaLength = 2400.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arena")
    float RiverWidth = 300.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arena")
    float LaneWidth = 260.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arena")
    float GroundHeight = 0.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arena")
    TArray<FVector> BlueSpawnPoints;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arena")
    TArray<FVector> RedSpawnPoints;

    UFUNCTION(BlueprintCallable, Category = "Arena")
    void BuildArena();

    UFUNCTION(BlueprintCallable, Category = "Arena")
    void SpawnDefaultTowers();

    UFUNCTION(BlueprintCallable, Category = "Arena")
    void CreateLaneWaypoints();
};
