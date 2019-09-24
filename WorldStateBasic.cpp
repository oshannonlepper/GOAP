#include "WorldStateBasic.h"

void GOAP::CWorldStateBasic::SetValue(const std::string& sKey, bool bValue)
{
	auto MapIt = WorldStateMap.lower_bound(sKey);
	if (bValue && MapIt == WorldStateMap.end())
	{
		WorldStateMap.emplace_hint(MapIt, sKey);
	}
	else if (!bValue && MapIt != WorldStateMap.end())
	{
		WorldStateMap.erase(sKey);
	}
}

bool GOAP::CWorldStateBasic::GetValue(const std::string& sKey) const
{
	return WorldStateMap.lower_bound(sKey) != WorldStateMap.end();
}
