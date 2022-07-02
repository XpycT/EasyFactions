// Fill out your copyright notice in the Description page of Project Settings.


#include "Reputation/ReputationComponent.h"

UReputationComponent::UReputationComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UReputationComponent::SetReputation(FFaction Faction, int32 Amount)
{
	if(Reputations.Num() == 0 || Faction.IsNone() || Amount == 0)
	{
		return;
	}
	
	for (FReputationItem& RepItem : Reputations)
	{
		
		if(RepItem.Faction == Faction)
		{
			RepItem.Value = FMath::Clamp(Amount, RepItem.MinValue, RepItem.MaxValue);
		}
	}
}

void UReputationComponent::AddReputation(FFaction Faction, int32 Amount)
{
	if(Reputations.Num() == 0 || Faction.IsNone() || Amount == 0)
	{
		return;
	}
	
	for (FReputationItem& RepItem : Reputations)
	{
		if(RepItem.Faction == Faction)
		{
			RepItem.Value = FMath::Clamp(RepItem.Value + Amount, RepItem.MinValue, RepItem.MaxValue);
		}
	}
}

