#pragma once

#include "CoreMinimal.h"
#include "BaseTroop.h"
#include "HeavyTroop.generated.h"

UCLASS()
class CLASHROYALERTS_API AHeavyTroop : public ABaseTroop
{
    GENERATED_BODY()

public:
    AHeavyTroop();

    virtual void BeginPlay() override;
};
