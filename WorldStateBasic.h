#pragma once

#include "IWorldState.h"

#include <unordered_set>

namespace GOAP
{

	/**
	 * Basic world state implementation.
	 *
	 * Contains a set of keys representing truths.
	 * If a given key exists in the set, GetValue returns true, otherwise it returns false.
	 */
	class CWorldStateBasic : public IWorldState
	{
	public:
		virtual ~CWorldStateBasic() {}

		// ~ Begin IWorldState Interface
		virtual void SetValue(const std::string& sKey, bool bValue) override;
		virtual bool GetValue(const std::string& sKey) const override;
		// ~ End IWorldState Interface

	private:
		std::unordered_set<std::string> WorldStateMap;
	};
}
