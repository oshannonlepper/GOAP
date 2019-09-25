#include <algorithm>

#include "IAStarNode.h"

template <typename THeuristicFunctor>
std::vector<IAStarNode*> CAStar<THeuristicFunctor>::ReconstructPath(const std::unordered_map<IAStarNode*, IAStarNode*>& CameFrom, IAStarNode* CurrentNode)
{
	std::vector<IAStarNode*> TotalPath = { CurrentNode };

	for (auto& CameFromIt : CameFrom)
	{
		IAStarNode* CameFromNode = CameFromIt.first;
		CameFromNode = CameFrom.at(CameFromNode);
		TotalPath.push_back(CameFromNode);
	}
	std::reverse(TotalPath.begin(), TotalPath.end());
	return TotalPath;
}

template <typename THeuristicFunctor>
bool CAStar<THeuristicFunctor>::FindPath(IAStarNode* Start, IAStarNode* Goal, std::vector<IAStarNode*>& OutPath)
{
	std::unordered_set<IAStarNode*> OpenSet = { Start };
	std::unordered_set<IAStarNode*> ClosedSet = {};
	std::unordered_map<IAStarNode*, IAStarNode*> CameFrom = {};

	std::unordered_map<IAStarNode*, float> CheapestKnownPathScoreMap;
	CheapestKnownPathScoreMap[Start] = 0;

	std::unordered_map<IAStarNode*, float> WeightedPathScoreMap;
	WeightedPathScoreMap[Start] = Heuristic(Start);

	while (OpenSet.size() > 0)
	{
		IAStarNode* CheapestWeightedNode = GetCheapestWeightedNode(OpenSet, WeightedPathScoreMap);
		if (CheapestWeightedNode == Goal)
		{
			OutPath = ReconstructPath(CameFrom, CheapestWeightedNode);
			return true;
		}

		OpenSet.erase(CheapestWeightedNode);
		ClosedSet.insert(CheapestWeightedNode);

		std::size_t NumNeighbours = CheapestWeightedNode->GetNumNeighbours();
		for (std::size_t NeighbourIndex = 0; NeighbourIndex < NumNeighbours; ++NeighbourIndex)
		{
			IAStarNode* CurrentNeighbour = CheapestWeightedNode->GetNeighbour(NeighbourIndex);
			auto ClosedSetIt = ClosedSet.find(CurrentNeighbour);
			if (ClosedSetIt != ClosedSet.end())
			{
				continue;
			}

			float CheapestKnownPathScore = 0.0f;
			auto CheapestKnownPathScoreIt = CheapestKnownPathScoreMap.find(CheapestWeightedNode);
			if (CheapestKnownPathScoreIt != CheapestKnownPathScoreMap.end())
			{
				CheapestKnownPathScore = CheapestKnownPathScoreIt->second + GetDistance(CheapestWeightedNode, CurrentNeighbour);
			}
			else
			{
				CheapestKnownPathScore = FLT_MAX;
			}

			auto NeighbourCheapestPathIt = CheapestKnownPathScoreMap.find(CurrentNeighbour);
			float NeighbourCheapestPath = (NeighbourCheapestPathIt != CheapestKnownPathScoreMap.end()) ? NeighbourCheapestPathIt->second : FLT_MAX;
			if (CheapestKnownPathScore < NeighbourCheapestPath)
			{
				CameFrom[CurrentNeighbour] = CheapestWeightedNode;
				CheapestKnownPathScoreMap[CurrentNeighbour] = CheapestKnownPathScore;
				WeightedPathScoreMap[CurrentNeighbour] = CheapestKnownPathScore + Heuristic(CurrentNeighbour);

				auto OpenSetIt = OpenSet.find(CurrentNeighbour);
				if (OpenSetIt == OpenSet.end())
				{
					OpenSet.insert(CurrentNeighbour);
				}
			}
		}
	}

	return false;
}

template <typename THeuristicFunctor>
float CAStar<THeuristicFunctor>::GetDistance(IAStarNode* FromNode, IAStarNode* ToNode)
{
	return 0.0f;
}

template <typename THeuristicFunctor>
IAStarNode* CAStar<THeuristicFunctor>::GetCheapestWeightedNode(const std::unordered_set<IAStarNode *>& OpenSet, const std::unordered_map<IAStarNode *, float>& WeightedPathScore) const
{
	IAStarNode* CheapestWeightedNode = nullptr;
	float CheapestWeightedNodeScore = FLT_MAX;
	for (IAStarNode* CompareNode : OpenSet)
	{
		auto WeightedPathScoreIt = WeightedPathScore.find(CompareNode);
		if (WeightedPathScoreIt != WeightedPathScore.end() && WeightedPathScoreIt->second < CheapestWeightedNodeScore)
		{
			CheapestWeightedNode = WeightedPathScoreIt->first;
			CheapestWeightedNodeScore = WeightedPathScoreIt->second;
		}
	}

	return CheapestWeightedNode;
}
