#pragma once

#include "IActionEffect.h"

#include <unordered_map>

namespace GOAP
{
	class CActionEffectBasic : public IActionEffect
	{
	public:
		virtual ~CActionEffectBasic() {}

		// ~ Begin IActionEffect Interface
		virtual void Apply(IWorldState* WorldState) const override;
		// ~ End IActionEffect Interface

	private:
		const std::unordered_map<std::string, bool> WorldStateEffectList;
	};
}
