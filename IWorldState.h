#pragma once

#include <string>

namespace GOAP
{
	/**
	 * A world state is a collection of flags corresponding to world truths.
	 * The world state is used by goals to determine whether they are satisfied,
	 * it is used by action pre-conditions and manipulated by action effects,
	 * and it is used by the planner to determine the appropriate sequence of
	 * actions required to satisfy a goal.
	 */
	struct IWorldState
	{
		virtual ~IWorldState() {}

		/**
		 * Set the value of the given key to the given bool value.
		 */
		virtual void SetValue(const std::string& sKey, bool bValue) = 0;

		/**
		 * Return the current value of the given key. Will return false
		 * if the key has not been set previously.
		 */
		virtual bool GetValue(const std::string& sKey) const = 0;
	};
}
