#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ClashRoyaleRTSGameModeBase.generated.h"

UCLASS()
class CLASHROYALERTS_API AClashRoyaleRTSGameModeBase : public AGameModeBase
{
    GENERATED_BODY()

public:
    AClashRoyaleRTSGameModeBase();

    virtual void BeginPlay() override;
    virtual void Tick(float DeltaSeconds) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arena")
    float MatchDuration = 180.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arena")
    int32 MaxElixir = 10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arena")
    float BaseElixirTick = 2.8f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arena")
    float FinalMinuteElixirTick = 1.4f;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Arena")
    float TimeRemaining = 180.f;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Arena")
    int32 CurrentElixir = 0;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Arena")
    bool bMatchOver = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arena")
    int32 BlueCrownCount = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arena")
    int32 RedCrownCount = 0;

    UFUNCTION(BlueprintCallable, Category = "Arena")
    void StartGame();

    UFUNCTION(BlueprintCallable, Category = "Arena")
    void GenerateElixir();

    UFUNCTION(BlueprintCallable, Category = "Arena")
    bool SpendElixir(int32 Cost);

    UFUNCTION(BlueprintCallable, Category = "Arena")
    void EndMatch(const FString& WinningSide);

    UFUNCTION(BlueprintCallable, Category = "Arena")
    void CheckForTimeWin();

    UFUNCTION(BlueprintCallable, Category = "Arena")
    void RegisterTowerDestroyed(const FString& TeamName);

protected:
    float ElixirAccumulator = 0.f;
    float CurrentElixirTick = 2.8f;
};
