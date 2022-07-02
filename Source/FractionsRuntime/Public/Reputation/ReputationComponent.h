// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Faction.h"
#include "ReputationComponent.generated.h"

USTRUCT(BlueprintType)
struct FACTIONSRUNTIME_API FReputationItem
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FFaction Faction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 Value;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ClampMax = 0))
	int32 MinValue;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ClampMin = 0))
	int32 MaxValue;
	
};

UCLASS(ClassGroup=(Factions), meta=(BlueprintSpawnableComponent))
class FACTIONSRUNTIME_API UReputationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UReputationComponent();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly , Category = "Reputation|Modification")
	TArray<FReputationItem> Reputations;

	UFUNCTION(BlueprintCallable, Category = "Reputation|Modification")
	void SetReputation(FFaction Faction, int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Reputation|Modification")
	void AddReputation(FFaction Faction, int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Reputation|Modification")
	FORCEINLINE TArray<FReputationItem> GetAllReputations() const { return Reputations; }
};
