#include <iostream>

#include "PlannerBasic.h"
#include "WorldStateBasic.h"

int main()
{
	using namespace GOAP;

	CPlannerBasic PlannerBasic;
	CWorldStateBasic WorldState;

	PlannerBasic.UpdateCurrentPlan(0.01f, &WorldState);

	return 0;
}
