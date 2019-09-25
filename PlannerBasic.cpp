#include "PlannerBasic.h"

#include "ActionBasic.h"

bool GOAP::CPlannerBasic::UpdateCurrentPlan(float DeltaTime, IWorldState* WorldState)
{
	if (CurrentPlan.size() == 0)
	{
		return false;
	}

	if (CActionBasic* CurrentAction = CurrentPlan[CurrentIndex])
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
			else if (CActionBasic* NewAction = CurrentPlan[CurrentIndex])
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
	// find actions that take us from goal to current world state
	std::vector<IAStarNode*> NewPlan;
	CActionBasic* StartNode = nullptr;
	CActionBasic* EndNode = nullptr;
	Pathfinder.FindPath(StartNode, EndNode, NewPlan);

	CurrentPlan.clear();
	for (IAStarNode* NewNode : NewPlan)
	{
		CurrentPlan.push_back(static_cast<CActionBasic*>(NewNode));
	}
}

void GOAP::CPlannerBasic::UpdateActionNeighbours()
{
	for (std::size_t ActionIndex = 0; ActionIndex < AvailableActions.size(); ++ActionIndex)
	{
		CActionBasic* Action = AvailableActions[ActionIndex];

		for (std::size_t OtherActionIndex = ActionIndex + 1; OtherActionIndex < AvailableActions.size(); ++OtherActionIndex)
		{
			CActionBasic* OtherAction = AvailableActions[OtherActionIndex];

			if (Action->GetDistance(OtherAction) <= 0.0f)
			{
				Action->AddNeighbouringAction(OtherAction);
			}
		}
	}
}

void GOAP::CPlannerBasic::AddAction(CActionBasic* InNewAction)
{
	AvailableActions.push_back(InNewAction);
}
