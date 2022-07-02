// Fill out your copyright notice in the Description page of Project Settings.


#include "FactionRelation.h"

#define LOCTEXT_NAMESPACE "FactionRelation"

FFactionRelation::FFactionRelation()
	: FactionA(FFaction::NoFaction)
	  , FactionB(FFaction::NoFaction)
	  , Attitude(ETeamAttitude::Neutral)
{
}

FFactionRelation::FFactionRelation(FFaction A, FFaction B, ETeamAttitude::Type InAttitude)
	: FactionA(A)
	  , FactionB(B)
	  , Attitude(InAttitude)
{
}

bool FFactionRelation::IsValid() const
{
	// Factions are the same or both are invalid
	return FactionA == FactionB || (!FactionA.IsNone() && !FactionB.IsNone());
}

bool FFactionRelation::operator==(const FFactionRelation& Other) const
{
	return (FactionA == Other.FactionA && FactionB == Other.FactionB)
		|| (FactionA == Other.FactionB && FactionB == Other.FactionA);
}

bool FFactionRelation::operator!=(const FFactionRelation& Other) const
{
	return !(*this == Other);
}

uint32 GetTypeHash(const FFactionRelation& InRelation)
{
	return GetTypeHash(InRelation.FactionA) ^ GetTypeHash(InRelation.FactionB);
}

#undef LOCTEXT_NAMESPACE