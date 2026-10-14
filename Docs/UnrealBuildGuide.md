#include "RTSCardBlueprintLibrary.h"

#include "TankTroop.h"
#include "RangedSplashTroop.h"
#include "SwarmTroop.h"
#include "HeavyTroop.h"

FDeckCard URTSCardBlueprintLibrary::MakeTankCard()
{
    FDeckCard Card;
    Card.CardName = TEXT("Tank");
    Card.ElixirCost = 4;
    Card.CardType = ECardType::Tank;
    Card.TroopClass = ATankTroop::StaticClass();
    Card.Description = TEXT("Slow tank that targets towers and buildings");
    return Card;
}

FDeckCard URTSCardBlueprintLibrary::MakeRangedSplashCard()
{
    FDeckCard Card;
    Card.CardName = TEXT("Baby Dragon");
    Card.ElixirCost = 4;
    Card.CardType = ECardType::RangedSplash;
    Card.TroopClass = ARangedSplashTroop::StaticClass();
    Card.Description = TEXT("Flying splash attacker that hits ground and air");
    return Card;
}

FDeckCard URTSCardBlueprintLibrary::MakeSwarmCard()
{
    FDeckCard Card;
    Card.CardName = TEXT("Skeletons");
    Card.ElixirCost = 3;
    Card.CardType = ECardType::Swarm;
    Card.TroopClass = ASwarmTroop::StaticClass();
    Card.Description = TEXT("Spawns a cluster of light melee units");
    return Card;
}

FDeckCard URTSCardBlueprintLibrary::MakeHeavyCard()
{
    FDeckCard Card;
    Card.CardName = TEXT("Knight");
    Card.ElixirCost = 3;
    Card.CardType = ECardType::Heavy;
    Card.TroopClass = AHeavyTroop::StaticClass();
    Card.Description = TEXT("Fast heavy melee unit with strong single-target damage");
    return Card;
}
