// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Faction.h"
#include "FactionInfoAsset.generated.h"

#define LOCTEXT_NAMESPACE "FactionInfoAsset"

/**
 * Struct containing information about a faction. Static use.
 */
UCLASS(Blueprintable, Abstract)
class FACTIONSRUNTIME_API UFactionInfoAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
};

#undef LOCTEXT_NAMESPACE

