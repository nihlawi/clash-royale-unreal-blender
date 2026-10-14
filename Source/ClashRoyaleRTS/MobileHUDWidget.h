#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MobileHUDWidget.generated.h"

UCLASS()
class CLASHROYALERTS_API UMobileHUDWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintImplementableEvent, Category = "HUD")
    void UpdateElixirBar(int32 Current, int32 Max);

    UFUNCTION(BlueprintImplementableEvent, Category = "HUD")
    void UpdateTimerText(float TimeRemaining);

    UFUNCTION(BlueprintImplementableEvent, Category = "HUD")
    void UpdateCrownText(int32 BlueCrowns, int32 RedCrowns);

    UFUNCTION(BlueprintImplementableEvent, Category = "HUD")
    void UpdateDeckCards(const TArray<FName>& CardNames, const FName& NextCardName);

    UFUNCTION(BlueprintImplementableEvent, Category = "HUD")
    void ShowResult(const FString& ResultText);
};
