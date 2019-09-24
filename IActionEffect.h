#pragma once

namespace GOAP
{
	struct IWorldState;
}

namespace GOAP
{
	/**
	 * An action effect defines the resulting behaviour/changes that occur
	 * after an action has been completed.
	 *
	 * Typically this is communicated as changes to the world state.
	 */
	struct IActionEffect
	{
		virtual ~IActionEffect() {}

		/**
		 * Called when the action has been completed. Applies this effect
		 * to the given world state.
		 */
		virtual void Apply(IWorldState* WorldState) const = 0;
	};
}
