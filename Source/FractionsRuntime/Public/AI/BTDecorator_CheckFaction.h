// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "GenericTeamAgentInterface.h"
#include "BTDecorator_CheckFaction.generated.h"

/**
 * 
 */
UCLASS()
class FACTIONSRUNTIME_API UBTDecorator_CheckFaction : public UBTDecorator
{
	GENERATED_BODY()

public:
	UBTDecorator_CheckFaction();

	virtual void OnGameplayTaskActivated(UGameplayTask& Task) override;
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

protected:
	UPROPERTY(EditAnywhere, Category="AI")
	FBlackboardKeySelector TargetActorKey;

	UPROPERTY(EditAnywhere, Category="AI")
	TEnumAsByte<ETeamAttitude::Type> Attitude;
};
