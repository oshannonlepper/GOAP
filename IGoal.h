#pragma once

namespace GOAP
{
	struct IWorldState;
}

namespace GOAP
{
	/**
	 * A goal represents an agent desire, it is any condition that an agent
	 * wants to satisfy.
	 */
	struct IGoal
	{
		virtual ~IGoal() {}

		/**
		 * Return true if this goal is currently satisfied (its conditions are met)
		 * Return false otherwise.
		 */
		virtual bool IsSatisfied(IWorldState* WorldState) const = 0;

		/**
		 * If the goal has not been satisfied, the priority tells us the importance
		 * of this goal. Goals with higher priorities are planned for first.
		 */
		virtual float GetPriority() const = 0;
	};
}
