#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DeckCard.h"
#include "DeckComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CLASHROYALERTS_API UDeckComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UDeckComponent();

    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Deck")
    TArray<FDeckCard> Pool;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Deck")
    TArray<FDeckCard> ActiveDeck;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Deck")
    int32 NextPreviewIndex = 0;

    UFUNCTION(BlueprintCallable, Category = "Deck")
    void InitializeDeck();

    UFUNCTION(BlueprintCallable, Category = "Deck")
    bool DrawCardAtIndex(int32 SlotIndex);

    UFUNCTION(BlueprintCallable, Category = "Deck")
    FDeckCard GetNextPreview() const;

    UFUNCTION(BlueprintCallable, Category = "Deck")
    void ReplaceUsedCard(int32 SlotIndex);
};
