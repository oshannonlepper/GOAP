#pragma once

namespace GOAP
{
	struct IWorldState;
}

namespace GOAP
{
	/**
	 * An action forms part of a plan for reaching a goal.
	 */
	struct IAction
	{
		virtual ~IAction() {}

		/**
		 * Return true if the action is valid, allowing it to be selected for a plan.
		 */
		virtual bool IsValid(IWorldState* WorldState) const = 0;

		/**
		 * Return the score for this action, higher scoring actions are
		 * more likely to be selected.
		 */
		virtual float GetScore() const = 0;

		/**
		 * Called by the owning plan when this action is started.
		 */
		virtual void BeginAction() = 0;

		/**
		 * Called every frame by the owning plan to update the action.
		 * Returns true if the action needs to continue updating.
		 * Returns false if the action is completed, telling the plan to
		 * process the end of this action.
		 * TODO - Return an enum, as we need to distinguish between a
		 * successful end, and an interrupted/failed end. (An interruption
		 * may want to trigger the planner to create a new plan)
		 */
		virtual bool UpdateAction(float DeltaTime) = 0;

		/**
		 * Called by the owning plan when this action is complete.
		 */
		virtual void EndAction(IWorldState* WorldState) = 0;
	};
}
