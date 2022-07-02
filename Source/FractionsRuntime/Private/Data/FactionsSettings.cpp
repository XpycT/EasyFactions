// Fill out your copyright notice in the Description page of Project Settings.


#include "FactionsSettings.h"
#include "FactionInfo.h"
#include "FactionsRuntime.h"

UFactionsSettings::UFactionsSettings()
{
	FactionList.RegisterFaction(TEXT("Default"), {FColor::Blue});

	FWorldDelegates::OnPostWorldInitialization.AddUObject(this, &UFactionsSettings::OnWorldInitialization);
}

void UFactionsSettings::BeginDestroy()
{
	FWorldDelegates::OnPostWorldInitialization.RemoveAll(this);
	
	UObject::BeginDestroy();
}

void UFactionsSettings::OnWorldInitialization(UWorld* World, const UWorld::InitializationValues IVS)
{
	//Initialize manager
	FFactionsRuntime::GetFactionManager();

	//Index relations
	Relations.IndexRelations();
}

#if WITH_EDITOR
bool UFactionsSettings::CanEditChange(const FProperty* InProperty) const
{
	bool bCanEdit = Super::CanEditChange(InProperty);

	FName PropertyName = InProperty ? InProperty->GetFName() : NAME_None;

	if (GET_MEMBER_NAME_CHECKED(FFactionRelation, Attitude) == PropertyName)
	{
		//TODO: Limit attitude depending on Faction
		bCanEdit &= true;
	}

	return bCanEdit;
}

#endif //WITH_EDITOR

bool UFactionsSettings::Internal_RegisterRelation(const FFactionRelation& Relation)
{
	if (!Relation.IsValid())
	{
		return false;
	}

	if (Relations.GetRelations().Add(Relation).IsValidId())
	{
		MarkPackageDirty();
		return true;
	}
	return false;
}

bool UFactionsSettings::Internal_UnregisterRelation(const FFactionRelation& Relation)
{
	if (!Relation.IsValid())
	{
		return false;
	}

	if (Relations.GetRelations().Remove(Relation) > 0)
	{
		MarkPackageDirty();
		return true;
	}
	return false;
}
