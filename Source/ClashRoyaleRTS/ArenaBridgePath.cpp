#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ArenaBridgePath.generated.h"

UCLASS()
class CLASHROYALERTS_API AArenaBridgePath : public AActor
{
    GENERATED_BODY()

public:
    AArenaBridgePath();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bridge")
    bool bIsBlueSideBridge = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bridge")
    int32 BridgeIndex = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bridge")
    TArray<FVector> Waypoints;
};
