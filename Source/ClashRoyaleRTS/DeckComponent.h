#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DeckCard.generated.h"

class ABaseTroop;

UENUM(BlueprintType)
enum class ECardType : uint8
{
    Tank,
    RangedSplash,
    Swarm,
    Heavy,
    Unknown
};

USTRUCT(BlueprintType)
struct FDeckCard
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Card")
    FName CardName = NAME_None;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Card")
    int32 ElixirCost = 3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Card")
    TSubclassOf<ABaseTroop> TroopClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Card")
    ECardType CardType = ECardType::Unknown;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Card")
    FString Description;
};
