#pragma once

#include <vector>

#include "IAction.h"

namespace GOAP
{
	struct IActionEffect;
	struct IActionPreCondition;
}

namespace GOAP
{
	/**
	 * Basic implementation of IAction.
	 */
	class CActionBasic : public IAction
	{
	public:
		CActionBasic() = default;

		CActionBasic(float InScore)
			: Score(InScore)
		{
		}

		CActionBasic(float InScore, const std::vector<IActionPreCondition*>& InPreConditions, const std::vector<IActionEffect*>& InEffects)
			: Score(InScore)
			, PreConditions(InPreConditions)
			, Effects(InEffects)
		{
		}

		virtual ~CActionBasic() {}

		// ~ Begin IAction Interface
		virtual bool IsValid(IWorldState* WorldState) const override;

		virtual float GetScore() const override { return Score; }

		virtual void BeginAction() override {}
		virtual bool UpdateAction(float DeltaTime) override { return false; }

		virtual void EndAction(IWorldState* WorldState) override;
		// ~ End IAction Interface

	private:

		// The score of this action, acts as a cost.
		const float Score = 0.0f;
		const std::vector<IActionPreCondition*> PreConditions;
		const std::vector<IActionEffect*> Effects;
	};
}
