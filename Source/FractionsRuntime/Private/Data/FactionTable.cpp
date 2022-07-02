// Fill out your copyright notice in the Description page of Project Settings.


#include "FactionTable.h"
#include "Faction.h"
#include "FactionInfo.h"


FFaction FFactionTable::RegisterFaction(FName Name, FFactionInfo Info)
{
	if (Items.Contains(Name))
	{
		return {};
	}

	Items.Add(Name, Info);
	return {Name};
}

bool FFactionTable::UnregisterFaction(FFaction Faction)
{
	if (Faction.IsNone())
	{
		return false;
	}

	return Items.Remove(Faction.GetIdName()) > 0;
}

bool FFactionTable::SetInfo(FFaction Faction, const FFactionInfo& NewInfo)
{
	if (Faction.IsNone())
	{
		return false;
	}

	FFactionInfo* const Info = Items.Find(Faction.GetIdName());
	if (Info)
	{
		*Info = NewInfo;
		return true;
	}
	return false;
}
