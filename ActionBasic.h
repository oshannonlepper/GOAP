#pragma once

#include <vector>

#include "IAction.h"
#include "IAStarNode.h"

namespace GOAP
{
	class CActionEffectBasic;
	class CActionPreConditionBasic;
}

namespace GOAP
{
	/**
	 * Basic implementation of IAction.
	 */
	class CActionBasic : public IAction, public IAStarNode
	{
	public:
		CActionBasic() = default;

		CActionBasic(float InScore)
			: Score(InScore)
		{
		}

		CActionBasic(float InScore, const std::vector<CActionPreConditionBasic*>& InPreConditions, const std::vector<CActionEffectBasic*>& InEffects)
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

		virtual float GetDistanceFromNextAction(IAction* NextAction) const override;
		// ~ End IAction Interface

		// ~ Begin IAStarNode Interface
		virtual std::size_t GetNumNeighbours() const override { return 0; }
		virtual IAStarNode* GetNeighbour(std::size_t Index) const override;
		virtual float GetDistance(IAStarNode* OtherNode) const override;
		// ~ End IAStarNode Interface

		void AddNeighbouringAction(CActionBasic* OtherAction);

	private:

		// The score of this action, acts as a cost.
		const float Score = 0.0f;
		const std::vector<CActionPreConditionBasic*> PreConditions;
		const std::vector<CActionEffectBasic*> Effects;

		std::vector<IAStarNode*> Neighbours;
	};
}
