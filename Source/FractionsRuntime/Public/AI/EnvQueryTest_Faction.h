﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "Faction.h"
#include "FactionsLibrary.h"
#include "EnvQueryTest_Faction.generated.h"

/**
 * 
 */
UCLASS(meta = (DisplayName = "Faction"))
class FACTIONSRUNTIME_API UEnvQueryTest_Faction : public UEnvQueryTest
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = Faction)
	EFactionTestMode Mode;

	UPROPERTY(EditAnywhere, Category = Faction)
	bool bCompareTowardsContextActor;

	UPROPERTY(EditAnywhere, Category = Faction, meta = (EditCondition = "!bCompareTowardsContextActor"))
	FFaction Faction;

	UPROPERTY(EditAnywhere, Category = Faction, meta = (EditCondition = "bCompareTowardsContextActor"))
	TSubclassOf<UEnvQueryContext> Context;


	UEnvQueryTest_Faction();

protected:

	virtual void RunTest(FEnvQueryInstance& QueryInstance) const override;

	virtual FText GetDescriptionTitle() const override;
	virtual FText GetDescriptionDetails() const override;
};
