#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DeployGhost.generated.h"

UCLASS()
class CLASHROYALERTS_API ADeployGhost : public AActor
{
    GENERATED_BODY()

public:
    ADeployGhost();

    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ghost")
    bool bIsVisible = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ghost")
    bool bIsValidPlacement = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ghost")
    FVector SpawnOffset = FVector(0.f, 0.f, 40.f);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ghost")
    FLinearColor ValidColor = FLinearColor(0.1f, 1.f, 0.2f, 0.55f);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ghost")
    FLinearColor InvalidColor = FLinearColor(1.f, 0.1f, 0.1f, 0.55f);

    UFUNCTION(BlueprintCallable, Category = "Ghost")
    void ShowGhostAtLocation(const FVector& Location, bool bValid);

    UFUNCTION(BlueprintCallable, Category = "Ghost")
    void HideGhost();

protected:
    UPROPERTY(VisibleAnywhere)
    class UStaticMeshComponent* GhostMesh;
};
