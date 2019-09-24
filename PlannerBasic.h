#pragma once

#include "IPlanner.h"

#include <vector>

namespace GOAP
{
	struct IAction;
}

namespace GOAP
{
	class CPlannerBasic : public IPlanner
	{
	public:
		virtual ~CPlannerBasic() {}

		// ~ Begin IPlanner Interface
		virtual bool UpdateCurrentPlan(float DeltaTime, IWorldState* WorldState) override;
		virtual void CreatePlan(IGoal* Goal, IWorldState* CurrentWorldState) override;
		// ~ End IPlanner Interface

	private:
		std::size_t CurrentIndex = 0;
		std::vector<IAction*> CurrentPlan;
	};
}
