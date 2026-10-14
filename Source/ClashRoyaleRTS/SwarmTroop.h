#include "HeavyTroop.h"

AHeavyTroop::AHeavyTroop()
{
    MaxHealth = 320.f;
    CurrentHealth = MaxHealth;
    MoveSpeed = 120.f;
    AttackRange = 140.f;
    Damage = 80.f;
    AttackCooldown = 1.4f;
}

void AHeavyTroop::BeginPlay()
{
    Super::BeginPlay();
}
