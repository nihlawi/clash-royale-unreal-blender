#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ElixirManager.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CLASHROYALERTS_API UElixirManager : public UActorComponent
{
    GENERATED_BODY()

public:
    UElixirManager();

    virtual void BeginPlay() override;
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Elixir")
    int32 MaxElixir = 10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Elixir")
    int32 CurrentElixir = 5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Elixir")
    float BaseTick = 2.8f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Elixir")
    float FinalMinuteTick = 1.4f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Elixir")
    float MatchTimeRemaining = 180.f;

    UFUNCTION(BlueprintCallable, Category = "Elixir")
    void GenerateElixir();

    UFUNCTION(BlueprintCallable, Category = "Elixir")
    bool SpendElixir(int32 Amount);

private:
    float ElixirAccumulator = 0.f;
};
