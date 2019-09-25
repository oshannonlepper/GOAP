#pragma once

#include "IActionPreCondition.h"

#include <unordered_map>

namespace GOAP
{
	class CActionPreConditionBasic : public IActionPreCondition
	{
	public:
		CActionPreConditionBasic() = default;
		CActionPreConditionBasic(const std::unordered_map<std::string, bool>& InRequirements)
			: Requirements(InRequirements)
		{
		}

		virtual ~CActionPreConditionBasic() {}

		// ~ Begin IActionPreCondition Interface
		virtual bool IsConditionMet(IWorldState* WorldState) const override;
		// ~ End IActionPreCondition Interface

		float GetNumConditionsNotMet(IWorldState* WorldState) const;

	private:
		const std::unordered_map<std::string, bool> Requirements;
	};
}
