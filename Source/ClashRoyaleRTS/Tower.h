#include "SwarmTroop.h"

ASwarmTroop::ASwarmTroop()
{
    MaxHealth = 80.f;
    CurrentHealth = MaxHealth;
    MoveSpeed = 170.f;
    AttackRange = 120.f;
    Damage = 15.f;
    AttackCooldown = 0.75f;
    SpawnCount = 3;
}

void ASwarmTroop::BeginPlay()
{
    Super::BeginPlay();
}
