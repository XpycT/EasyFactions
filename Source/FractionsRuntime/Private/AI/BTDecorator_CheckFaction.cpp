// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTDecorator_CheckFaction.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "FactionsLibrary.h"

UBTDecorator_CheckFaction::UBTDecorator_CheckFaction()
{
	NodeName = TEXT("Check Faction");
}

void UBTDecorator_CheckFaction::OnGameplayTaskActivated(UGameplayTask& Task)
{
	Super::OnGameplayTaskActivated(Task);
}

bool UBTDecorator_CheckFaction::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	if (!Super::CalculateRawConditionValue(OwnerComp, NodeMemory))
	{
		return false;
	}
	const UBlackboardComponent* BlackBoardComp = OwnerComp.GetBlackboardComponent();
	if (ensure(BlackBoardComp))
	{
		if (const APawn* AIPawn = OwnerComp.GetAIOwner()->GetPawn())
		{
			if (const AActor* TargetActor = Cast<AActor>(BlackBoardComp->GetValueAsObject(TargetActorKey.SelectedKeyName)))
			{
				const TEnumAsByte<ETeamAttitude::Type> TargetAttitude = UFactionsLibrary::GetAttitudeTowards(AIPawn, TargetActor);
				if (TargetAttitude == Attitude)
				{
					return true;
				}
			}
		}
	}

	return false;
}
