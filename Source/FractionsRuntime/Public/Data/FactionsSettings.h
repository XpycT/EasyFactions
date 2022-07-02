// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FactionTable.h"
#include "Engine/World.h"
#include "RelationTable.h"
#include "UObject/Object.h"
#include "FactionsSettings.generated.h"

/**
 * Find Custom Config documentation here: https://unrealcommunity.wiki/customsettings-yrdju84k
 */
UCLASS(config = Game, defaultconfig)
class FACTIONSRUNTIME_API UFactionsSettings : public UObject
{
	GENERATED_BODY()

public:
	UFactionsSettings();

	UPROPERTY(config, EditAnywhere, Category = Factions, SaveGame)
	FRelationTable Relations;
	
protected:
	
	UPROPERTY(config, EditAnywhere, Category = "Factions", SaveGame)
	FFactionTable FactionList;

	virtual void BeginDestroy() override;

	void OnWorldInitialization(UWorld* World, const UWorld::InitializationValues IVS);

#if WITH_EDITOR
	virtual bool CanEditChange(const FProperty* InProperty) const override;
#endif

public:
	
	bool Internal_RegisterRelation(const FFactionRelation& Relation);
	bool Internal_UnregisterRelation(const FFactionRelation& Relation);
	
	const FFactionRelation* FindRelation(const FFaction& A, const FFaction& B) const
	{
		return Relations.GetRelations().Find({ A, B });
	}

	FFactionTable& GetFactionTable() { return FactionList; }
	const TMap<FName, FFactionInfo>& GetFactionInfos() const { return FactionList.Items; }
};
