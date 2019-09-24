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
