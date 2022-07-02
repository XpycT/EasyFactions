// Fill out your copyright notice in the Description page of Project Settings.


#include "FactionsLibrary.h"

#include "EngineUtils.h"
#include "FactionsRuntime.h"
#include "FactionsSettings.h"
#include "FactionInfo.h"
#include "Faction.h"

FFaction UFactionsLibrary::RegisterFaction(const FName& Name, const FFactionInfo& FactionInfo)
{
	UFactionsSettings* Settings = FFactionsRuntime::GetFactionManager();
	check(Settings);

	return Settings->GetFactionTable().RegisterFaction(Name, FactionInfo);
}

bool UFactionsLibrary::UnregisterFaction(FFaction Faction)
{
	UFactionsSettings* Settings = FFactionsRuntime::GetFactionManager();
	check(Settings);

	return Settings->GetFactionTable().UnregisterFaction(Faction);
}

void UFactionsLibrary::GetAllFactions(TArray<FFaction>& Factions)
{
	const UFactionsSettings* Settings = FFactionsRuntime::GetFactionManager();
	check(Settings);

	const auto& AllFactions = Settings->GetFactionInfos();

	Factions.Reserve(Factions.Num() + AllFactions.Num());

	for (const auto& Entry : AllFactions)
	{
		Factions.Add({Entry.Key});
	}
}

bool UFactionsLibrary::RegisterRelation(const FFactionRelation& NewRelation)
{
	UFactionsSettings* Settings = FFactionsRuntime::GetFactionManager();
	check(Settings);

	return Settings->Internal_RegisterRelation(NewRelation);
}

bool UFactionsLibrary::UnregisterRelation(const FFactionRelation& Relation)
{
	UFactionsSettings* Settings = FFactionsRuntime::GetFactionManager();
	check(Settings);

	return Settings->Internal_UnregisterRelation(Relation);
}

bool UFactionsLibrary::GetAllActorsWithFaction(const UObject* ContextObject, const FFaction Faction, EFactionTestMode Comparison, TSubclassOf<AActor> ActorClass,
                                               TArray<AActor*>& OutActors)
{
	QUICK_SCOPE_CYCLE_COUNTER(UGameplayStatics_GetAllActorsOfClass);
	OutActors.Reset();

	if (Faction.IsNone() || !ActorClass)
	{
		return false;
	}

	UWorld* World = GEngine->GetWorldFromContextObject(ContextObject, EGetWorldErrorMode::ReturnNull);
	if (World)
	{
		switch (Comparison)
		{
		case EFactionTestMode::IsTheSame:
			for (TActorIterator<AActor> It(World, ActorClass); It; ++It)
			{
				AActor* Actor = *It;
				if (IsValid(Actor) && UFactionsLibrary::GetFaction(Actor) == Faction)
				{
					OutActors.Add(Actor);
				}
			}
			break;
		case EFactionTestMode::IsFriendly:
			for (TActorIterator<AActor> It(World, ActorClass); It; ++It)
			{
				AActor* Actor = *It;
				if (IsValid(Actor) && UFactionsLibrary::GetFaction(Actor).IsFriendlyTowards(Faction))
				{
					OutActors.Add(Actor);
				}
			}
			break;
		case EFactionTestMode::IsNeutral:
			for (TActorIterator<AActor> It(World, ActorClass); It; ++It)
			{
				AActor* Actor = *It;
				if (IsValid(Actor) && UFactionsLibrary::GetFaction(Actor).IsNeutralTowards(Faction))
				{
					OutActors.Add(Actor);
				}
			}
			break;
		case EFactionTestMode::IsHostile:
			for (TActorIterator<AActor> It(World, ActorClass); It; ++It)
			{
				AActor* Actor = *It;
				if (IsValid(Actor) && UFactionsLibrary::GetFaction(Actor).IsHostileTowards(Faction))
				{
					OutActors.Add(Actor);
				}
			}
			break;
		}

		return OutActors.Num() > 0;
	}

	return false;
}
