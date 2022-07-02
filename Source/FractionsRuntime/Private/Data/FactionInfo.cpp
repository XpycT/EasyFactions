// Fill out your copyright notice in the Description page of Project Settings.


#include "FactionInfo.h"


#define LOCTEXT_NAMESPACE "FactionInfo"

FFactionInfo::FFactionInfo(FLinearColor InColor)
	: DisplayName(LOCTEXT("FactionDisplayName", ""))
	  , Color(InColor)
	  , AttitudeTowardsItself(ETeamAttitude::Friendly)
	  , DefaultAttitudeTowardsOthers(ETeamAttitude::Neutral)
	  , InfoAsset()
{
}

FFactionInfo::FFactionInfo(FText DisplayName, FLinearColor InColor)
	: DisplayName(DisplayName)
	  , Color(InColor)
	  , AttitudeTowardsItself(ETeamAttitude::Friendly)
	  , DefaultAttitudeTowardsOthers(ETeamAttitude::Neutral)
	  , InfoAsset()
{
}

#undef LOCTEXT_NAMESPACE