#pragma once

#include "AStar.h"
#include "IPlanner.h"

#include <vector>

namespace GOAP
{
	class CActionBasic;
}

namespace GOAP
{
	struct SPlannerHeuristic
	{
		float operator ()(IAStarNode* Node)
		{
			return 1.0f;
		}
	};

	class CPlannerBasic : public IPlanner
	{
	public:
		virtual ~CPlannerBasic() {}

		// ~ Begin IPlanner Interface
		virtual bool UpdateCurrentPlan(float DeltaTime, IWorldState* WorldState) override;
		virtual void CreatePlan(IGoal* Goal, IWorldState* CurrentWorldState) override;
		// ~ End IPlanner Interface

		void UpdateActionNeighbours();

		void AddAction(CActionBasic* InNewAction);

	private:
		std::size_t CurrentIndex = 0;
		std::vector<CActionBasic*> CurrentPlan;
		std::vector<CActionBasic*> AvailableActions;
		CAStar<SPlannerHeuristic> Pathfinder;
	};
}
