#include "ActionEffectBasic.h"

#include "IWorldState.h"

void GOAP::CActionEffectBasic::Apply(IWorldState* WorldState) const
{
	for (const auto& WorldStateEffect : WorldStateEffectList)
	{
		WorldState->SetValue(WorldStateEffect.first, WorldStateEffect.second);
	}
}
