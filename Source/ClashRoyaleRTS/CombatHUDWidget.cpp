#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CombatHUDWidget.generated.h"

UCLASS()
class CLASHROYALERTS_API UCombatHUDWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "HUD")
    void UpdateElixir(int32 Current, int32 Max);

    UFUNCTION(BlueprintCallable, Category = "HUD")
    void UpdateTimer(float TimeRemaining);

    UFUNCTION(BlueprintCallable, Category = "HUD")
    void UpdateCrowns(int32 BlueCrowns, int32 RedCrowns);

    UFUNCTION(BlueprintCallable, Category = "HUD")
    void UpdateDeck(TArray<FName> CardNames, FName NextPreview);

    UFUNCTION(BlueprintCallable, Category = "HUD")
    void ShowMatchResult(const FString& ResultText);
};
