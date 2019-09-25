#include "ActionPreConditionBasic.h"

#include "IWorldState.h"

bool GOAP::CActionPreConditionBasic::IsConditionMet(IWorldState* WorldState) const
{
	for (const auto& RequirementPair : Requirements)
	{
		if (WorldState->GetValue(RequirementPair.first) != WorldState->GetValue(RequirementPair.first))
		{
			return false;
		}
	}

	return true;
}

float GOAP::CActionPreConditionBasic::GetNumConditionsNotMet(IWorldState* WorldState) const
{
	float ReturnValue = 0.0f;

	for (const auto& Pair : Requirements)
	{
		if (WorldState->GetValue(Pair.first) != Pair.second)
		{
			ReturnValue += 1.0f;
		}
	}

	return ReturnValue;
}
