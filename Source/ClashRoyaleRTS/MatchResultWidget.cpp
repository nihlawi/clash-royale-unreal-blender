#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MatchResultWidget.generated.h"

UCLASS()
class CLASHROYALERTS_API UMatchResultWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintImplementableEvent, Category = "Result")
    void SetResultText(const FString& Message);

    UFUNCTION(BlueprintImplementableEvent, Category = "Result")
    void ShowResult();

    UFUNCTION(BlueprintImplementableEvent, Category = "Result")
    void HideResult();
};
