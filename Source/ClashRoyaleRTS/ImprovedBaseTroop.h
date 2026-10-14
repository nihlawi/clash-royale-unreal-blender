#pragma once

#include "CoreMinimal.h"
#include "BaseTroop.h"
#include "GameFramework/Actor.h"
#include "ImprovedBaseTroop.generated.h"

UCLASS()
class CLASHROYALERTS_API AImprovedBaseTroop : public ABaseTroop
{
    GENERATED_BODY()

public:
    AImprovedBaseTroop();

    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

protected:
    // How often (seconds) the troop searches for targets
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    float TargetSearchInterval = 0.35f;

    float TargetSearchAccumulator = 0.f;

    virtual bool FindClosestEnemyTarget() override;
};
