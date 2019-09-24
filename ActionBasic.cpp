#include "ActionBasic.h"

#include "IActionEffect.h"
#include "IActionPreCondition.h"

namespace GOAP
{
	bool CActionBasic::IsValid(IWorldState* WorldState) const
	{
		for (const IActionPreCondition* const PreCondition : PreConditions)
		{
			if (!PreCondition->IsConditionMet(WorldState))
			{
				return false;
			}
		}

		return true;
	}

	void CActionBasic::EndAction(IWorldState* WorldState)
	{
		for (const IActionEffect* const Effect : Effects)
		{
			Effect->Apply(WorldState);
		}
	}
}
