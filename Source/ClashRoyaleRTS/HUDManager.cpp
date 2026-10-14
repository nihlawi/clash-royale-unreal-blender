#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HUDManager.generated.h"

class UUserWidget;
class UCombatHUDWidget;

UCLASS()
class CLASHROYALERTS_API AHUDManager : public AActor
{
    GENERATED_BODY()

public:
    AHUDManager();

    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
    TSubclassOf<UUserWidget> HUDWidgetClass;

    UPROPERTY()
    UCombatHUDWidget* CombatHUD;

    UFUNCTION(BlueprintCallable, Category = "HUD")
    void UpdateElixir(int32 Current, int32 Max);

    UFUNCTION(BlueprintCallable, Category = "HUD")
    void UpdateTimer(float TimeRemaining);

    UFUNCTION(BlueprintCallable, Category = "HUD")
    void UpdateCrowns(int32 BlueCrowns, int32 RedCrowns);
};
