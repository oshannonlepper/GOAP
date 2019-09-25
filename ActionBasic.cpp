#include "ActionBasic.h"

#include "ActionEffectBasic.h"
#include "ActionPreConditionBasic.h"
#include "WorldStateBasic.h"

#include <cassert>

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
		for (const CActionEffectBasic* const Effect : Effects)
		{
			Effect->Apply(WorldState);
		}
	}

	float CActionBasic::GetDistanceFromNextAction(IAction* NextAction) const
	{
		// TODO - this is trying to do the heuristic logic, move to heuristic functor?
		// heuristic = number of unsatisfied world state properties

		// compare this action effects with other action preconditions
		// if they match, then they are neighbours (think dominoes)

		float ReturnValue = 0.0f;

		CActionBasic* OtherNodeAsAction = static_cast<CActionBasic*>(NextAction);

		CWorldStateBasic TransientWorldState;
		for (CActionEffectBasic* Effect : Effects)
		{
			Effect->Apply(&TransientWorldState);
		}

		for (CActionPreConditionBasic* PreCondition : PreConditions)
		{
			ReturnValue += PreCondition->GetNumConditionsNotMet(&TransientWorldState);
		}

		return ReturnValue;
	}

	IAStarNode* CActionBasic::GetNeighbour(std::size_t Index) const
	{
		assert(Index < Neighbours.size());

		return Neighbours[Index];
	}

	float CActionBasic::GetDistance(IAStarNode* OtherNode) const
	{
		CActionBasic* OtherNodeAsAction = static_cast<CActionBasic*>(OtherNode);
		return GetDistanceFromNextAction(OtherNodeAsAction);
	}

	void CActionBasic::AddNeighbouringAction(CActionBasic* OtherAction)
	{
		Neighbours.push_back(OtherAction);
	}
}
