// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
#include "Engine/Texture.h"
#include "Faction.h"
#include "FactionInfoAsset.h"
#include "FactionInfo.generated.h"

/**
 * Struct containing information about a faction. Static use.
 */
USTRUCT(BlueprintType)
struct FACTIONSRUNTIME_API FFactionInfo
{
	GENERATED_BODY()
	
public:
	FFactionInfo(FLinearColor InColor = FColor::Cyan);
	FFactionInfo(FText DisplayName, FLinearColor InColor = FColor::Cyan);
	
	// Name of the faction
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Faction")
	FText DisplayName;

	// Color of the faction
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Faction")
	FLinearColor Color;

	// Attitude this faction will have against itself. Relations will override it
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Faction")
	TEnumAsByte<ETeamAttitude::Type> AttitudeTowardsItself;
	
	// Attitude this faction will have against others. Relations will override it
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Faction")
	TEnumAsByte<ETeamAttitude::Type> DefaultAttitudeTowardsOthers;

	// Icon of the faction
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Faction")
	TSoftObjectPtr<UTexture> Icon;

	/**
	 * Asset containing optional extra fields for a faction.
	 * Create a class from UFactionInfoAsset to create your own fields (either in C++ or BPs)
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Faction", meta = (DisplayThumbnail = false))
	TSoftObjectPtr<UFactionInfoAsset> InfoAsset;
};
