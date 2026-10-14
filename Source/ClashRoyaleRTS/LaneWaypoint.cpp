#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LaneWaypoint.generated.h"

UCLASS()
class CLASHROYALERTS_API ALaneWaypoint : public AActor
{
    GENERATED_BODY()

public:
    ALaneWaypoint();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lane")
    int32 LaneIndex = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lane")
    bool bIsBridgeNode = false;
};
