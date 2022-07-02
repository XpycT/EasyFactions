// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
#include "Faction.h"
#include "FactionRelation.generated.h"

/**
 * Defines a relation between factions
*/
USTRUCT(BlueprintType)
struct FACTIONSRUNTIME_API FFactionRelation
{
	GENERATED_USTRUCT_BODY()

public:
	FFactionRelation();
	FFactionRelation(FFaction A, FFaction B, ETeamAttitude::Type InAttitude = ETeamAttitude::Neutral);
	
	bool IsValid() const;

	bool operator==(const FFactionRelation& Other) const;
	bool operator!=(const FFactionRelation& Other) const;

	friend uint32 GetTypeHash(const FFactionRelation& InRelation);
public:

	// First Faction of the relation
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Relation", meta = (DisplayName = "Faction A"))
	FFaction FactionA;

	// Second Faction of the relation
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Relation", meta = (DisplayName = "Faction B"))
	FFaction FactionB;

	// Defines how this two factions will react to each other
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Relation", meta = (DisplayName = "Factions Attitude"))
	TEnumAsByte<ETeamAttitude::Type> Attitude;
	
};
