#include "RangedSplashTroop.h"

ARangedSplashTroop::ARangedSplashTroop()
{
    MaxHealth = 250.f;
    CurrentHealth = MaxHealth;
    MoveSpeed = 110.f;
    AttackRange = 320.f;
    Damage = 30.f;
    AttackCooldown = 1.1f;
}

void ARangedSplashTroop::BeginPlay()
{
    Super::BeginPlay();
}
