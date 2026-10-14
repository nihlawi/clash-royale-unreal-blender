#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DeckCard.h"
#include "RTSCardBlueprintLibrary.generated.h"

UCLASS()
class CLASHROYALERTS_API URTSCardBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure, Category = "RTS Card")
    static FDeckCard MakeTankCard();

    UFUNCTION(BlueprintPure, Category = "RTS Card")
    static FDeckCard MakeRangedSplashCard();

    UFUNCTION(BlueprintPure, Category = "RTS Card")
    static FDeckCard MakeSwarmCard();

    UFUNCTION(BlueprintPure, Category = "RTS Card")
    static FDeckCard MakeHeavyCard();
};
