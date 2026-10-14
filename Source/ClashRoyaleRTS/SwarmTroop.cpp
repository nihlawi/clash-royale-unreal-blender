#pragma once

#include "CoreMinimal.h"
#include "BaseTroop.h"
#include "SwarmTroop.generated.h"

UCLASS()
class CLASHROYALERTS_API ASwarmTroop : public ABaseTroop
{
    GENERATED_BODY()

public:
    ASwarmTroop();

    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Swarm")
    int32 SpawnCount = 3;
};
