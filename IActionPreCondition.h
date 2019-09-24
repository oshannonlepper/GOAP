#pragma once

namespace GOAP
{
	struct IWorldState;
}

namespace GOAP
{
	/**
	 * Interface for a pre-condition, which is a condition that must be met
	 * in order for an action to be selected as part of the plan for a goal.
	 */
	struct IActionPreCondition
	{
		virtual ~IActionPreCondition() {}

		/** Given the world state, return true if this pre-condition has been met. */
		virtual bool IsConditionMet(IWorldState* WorldState) const = 0;
	};
}
