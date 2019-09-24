#pragma once

namespace GOAP
{
	struct IGoal;
	struct IWorldState;
}

namespace GOAP
{
	/**
	 * The planner determines appropriate goals for an agent and sequences
	 * an appropriate set of actions (a plan) to execute in order for its
	 * target agent to reach the desired goal.
	 */
	struct IPlanner
	{
		virtual ~IPlanner() {}

		/**
		 * Called every frame to update the planner's current plan.
		 * Return true if the plan needs to continue updating.
		 * Return false if the plan has ended or been interrupted.
		 * TODO - Consider returning an enum so that the fail reason can be deduced.
		 */
		virtual bool UpdateCurrentPlan(float DeltaTime, IWorldState* WorldState) = 0;
		
		/**
		 * Called when a new plan is needed or the owning agent.
		 * Compares the current world state with the goal and builds
		 * a sequence of actions that bring us to the world state
		 * afforded by the given goal.
		 */
		virtual void CreatePlan(IGoal* Goal, IWorldState* CurrentWorldState) = 0;
	};
}
