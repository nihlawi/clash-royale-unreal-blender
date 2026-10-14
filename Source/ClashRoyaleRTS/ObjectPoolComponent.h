#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ObjectPoolComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CLASHROYALERTS_API UObjectPoolComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UObjectPoolComponent();

    // Setup the pool with a given actor class and initial size
    UFUNCTION(BlueprintCallable, Category = "Pool")
    void InitializePool(TSubclassOf<AActor> ActorClass, int32 InitialSize = 10);

    // Acquire an actor from the pool (activates it)
    UFUNCTION(BlueprintCallable, Category = "Pool")
    AActor* AcquireFromPool();

    // Return an actor back to the pool (deactivates it)
    UFUNCTION(BlueprintCallable, Category = "Pool")
    void ReleaseToPool(AActor* Actor);

protected:
    virtual void BeginPlay() override;

    UPROPERTY()
    TSubclassOf<AActor> PooledClass;

    UPROPERTY()
    TArray<AActor*> Pool;

    UPROPERTY(EditAnywhere, Category = "Pool")
    bool bAutoExpand = true;
};
