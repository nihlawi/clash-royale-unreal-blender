#pragma once

#include "CoreMinimal.h"
#include "BaseTroop.h"
#include "RangedSplashTroop.generated.h"

UCLASS()
class CLASHROYALERTS_API ARangedSplashTroop : public ABaseTroop
{
    GENERATED_BODY()

public:
    ARangedSplashTroop();

    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float SplashRadius = 150.f;
};
