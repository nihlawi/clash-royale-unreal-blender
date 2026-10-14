#include "TankTroop.h"

ATankTroop::ATankTroop()
{
    MaxHealth = 500.f;
    CurrentHealth = MaxHealth;
    MoveSpeed = 70.f;
    AttackRange = 170.f;
    Damage = 35.f;
    AttackCooldown = 1.3f;
}

void ATankTroop::BeginPlay()
{
    Super::BeginPlay();
}
