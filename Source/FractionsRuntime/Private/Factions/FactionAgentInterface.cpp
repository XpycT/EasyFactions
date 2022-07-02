// Fill out your copyright notice in the Description page of Project Settings.


#include "Factions/FactionAgentInterface.h"

FFaction IFactionAgentInterface::GetFaction(const AActor* Other)
{
	if (Other && Other->Implements<UFactionAgentInterface>())
	{
		FFaction OtherFaction;
		IFactionAgentInterface::Execute_EventGetFaction(Other, OtherFaction);
		return OtherFaction;
	}
	return FFaction::NoFaction;
}

void IFactionAgentInterface::SetFaction(AActor* Other, const FFaction& NewFaction)
{
	if (Other && Other->Implements<UFactionAgentInterface>())
	{
		IFactionAgentInterface::Execute_EventSetFaction(Other, NewFaction);
	}
}

const ETeamAttitude::Type IFactionAgentInterface::GetAttitudeTowards(const AActor& Other) const
{
	const FFaction OtherFaction = IFactionAgentInterface::GetFaction(&Other);
	return GetFaction().GetAttitudeTowards(OtherFaction);
}

FFaction IFactionAgentInterface::GetFaction() const
{
	return FFaction::NoFaction;
}

void IFactionAgentInterface::SetFaction(const FFaction& Faction)
{
	// By default call BP event
	IFactionAgentInterface::Execute_EventSetFaction(Cast<UObject>(this), Faction);
}
