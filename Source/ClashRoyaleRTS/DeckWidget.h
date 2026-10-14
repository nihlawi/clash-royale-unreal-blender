#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DeckWidget.generated.h"

UCLASS()
class CLASHROYALERTS_API UDeckWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    // Called from UMG button for a slot to try to deploy that card using current pointer/mouse position
    UFUNCTION(BlueprintCallable, Category = "Deck")
    bool DeployCardFromSlot(int32 SlotIndex);

    // Update visual representation of deck. Implement in BP.
    UFUNCTION(BlueprintImplementableEvent, Category = "Deck")
    void UpdateDeckVisuals(const TArray<FName>& CardNames, const FName& NextPreview);
};
