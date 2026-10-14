#pragma once

#include "CoreMinimal.h"
#include "BaseTroop.h"
#include "TankTroop.generated.h"

UCLASS()
class CLASHROYALERTS_API ATankTroop : public ABaseTroop
{
    GENERATED_BODY()

public:
    ATankTroop();

    virtual void BeginPlay() override;
};
