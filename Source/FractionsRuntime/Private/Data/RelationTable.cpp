// Fill out your copyright notice in the Description page of Project Settings.


#include "RelationTable.h"

void FRelationTable::IndexRelations()
{
	// Avoid memory deallocation
	IndexedList.Empty(ConfigList.Num());
	// Reduce possible memory allocation
	IndexedList.Reserve(ConfigList.Num());

	for (const auto& Relation : ConfigList)
	{
		IndexedList.Add(Relation);
	}
}
