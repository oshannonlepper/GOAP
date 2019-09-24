#include "PlannerBasic.h"

#include "IAction.h"

bool GOAP::CPlannerBasic::UpdateCurrentPlan(float DeltaTime, IWorldState* WorldState)
{
	if (CurrentPlan.size() == 0)
	{
		return false;
	}

	if (IAction* CurrentAction = CurrentPlan[CurrentIndex])
	{
		bool bUpdateResult = CurrentAction->UpdateAction(DeltaTime);

		if (!bUpdateResult)
		{
			CurrentAction->EndAction(WorldState);
			++CurrentIndex;
			if (CurrentIndex >= CurrentPlan.size())
			{
				return false;
			}
			else if (IAction* CurrentAction = CurrentPlan[CurrentIndex])
			{
				CurrentAction->BeginAction();
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}

	return true;
}

void GOAP::CPlannerBasic::CreatePlan(IGoal* Goal, IWorldState* WorldState)
{
}
