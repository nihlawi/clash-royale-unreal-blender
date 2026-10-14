#include "DeckComponent.h"

UDeckComponent::UDeckComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UDeckComponent::BeginPlay()
{
    Super::BeginPlay();
    InitializeDeck();
}

void UDeckComponent::InitializeDeck()
{
    ActiveDeck.Empty();
    if (Pool.Num() < 4)
    {
        return;
    }

    for (int32 Index = 0; Index < 4; ++Index)
    {
        ActiveDeck.Add(Pool[Index]);
    }

    NextPreviewIndex = 4;
}

bool UDeckComponent::DrawCardAtIndex(int32 SlotIndex)
{
    if (SlotIndex < 0 || SlotIndex >= ActiveDeck.Num())
    {
        return false;
    }

    ReplaceUsedCard(SlotIndex);
    return true;
}

FDeckCard UDeckComponent::GetNextPreview() const
{
    if (Pool.Num() == 0)
    {
        FDeckCard EmptyCard;
        EmptyCard.CardName = NAME_None;
        EmptyCard.ElixirCost = 0;
        EmptyCard.CardType = ECardType::Unknown;
        return EmptyCard;
    }

    if (NextPreviewIndex >= Pool.Num())
    {
        return Pool[0];
    }

    return Pool[NextPreviewIndex];
}

void UDeckComponent::ReplaceUsedCard(int32 SlotIndex)
{
    if (Pool.Num() == 0)
    {
        return;
    }

    if (NextPreviewIndex >= Pool.Num())
    {
        NextPreviewIndex = 0;
    }

    if (SlotIndex >= 0 && SlotIndex < ActiveDeck.Num())
    {
        ActiveDeck[SlotIndex] = Pool[NextPreviewIndex];
    }

    NextPreviewIndex = (NextPreviewIndex + 1) % Pool.Num();
}
