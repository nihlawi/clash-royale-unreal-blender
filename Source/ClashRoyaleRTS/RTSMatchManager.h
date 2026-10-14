#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RTSMatchManager.generated.h"

UCLASS()
class CLASHROYALERTS_API ARTSMatchManager : public AActor
{
    GENERATED_BODY()

public:
    ARTSMatchManager();

    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Match")
    float MatchDuration = 180.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Match")
    float CurrentTimeRemaining = 180.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Match")
    int32 MaxElixir = 10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Match")
    int32 CurrentBlueElixir = 5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Match")
    int32 CurrentRedElixir = 5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Match")
    int32 BlueCrowns = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Match")
    int32 RedCrowns = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Match")
    bool bMatchFinished = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Match")
    FString WinnerText = TEXT("In Progress");

    UFUNCTION(BlueprintCallable, Category = "Match")
    void StartMatch();

    UFUNCTION(BlueprintCallable, Category = "Match")
    void TickElixir(float DeltaTime);

    UFUNCTION(BlueprintCallable, Category = "Match")
    void GenerateBlueElixir();

    UFUNCTION(BlueprintCallable, Category = "Match")
    void GenerateRedElixir();

    UFUNCTION(BlueprintCallable, Category = "Match")
    bool TrySpendBlueElixir(int32 Cost);

    UFUNCTION(BlueprintCallable, Category = "Match")
    bool TrySpendRedElixir(int32 Cost);

    UFUNCTION(BlueprintCallable, Category = "Match")
    void RegisterBlueTowerDestroyed();

    UFUNCTION(BlueprintCallable, Category = "Match")
    void RegisterRedTowerDestroyed();

    UFUNCTION(BlueprintCallable, Category = "Match")
    void ResolveTimeEnd();

    UFUNCTION(BlueprintCallable, Category = "Match")
    void FinishMatch(const FString& Winner);
};
