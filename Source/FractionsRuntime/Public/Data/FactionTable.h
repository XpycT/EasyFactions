// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FactionTable.generated.h"

struct FFaction;
struct FFactionInfo;

USTRUCT()
struct FACTIONSRUNTIME_API FFactionTable
{
	GENERATED_BODY()

public:

	UPROPERTY(config, EditAnywhere, Category = "Factions", SaveGame)
	TMap<FName, FFactionInfo> Items;
	
	FFaction RegisterFaction(FName Name, FFactionInfo Info);
	
	bool UnregisterFaction(FFaction Faction);

	bool SetInfo(FFaction Faction, const FFactionInfo& NewInfo);
};