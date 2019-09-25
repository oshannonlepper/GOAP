#pragma once

#include <vector>
#include <unordered_map>
#include <unordered_set>

struct IAStarNode;

template <typename THeuristicFunctor>
class CAStar
{
public:
	std::vector<IAStarNode*> ReconstructPath(const std::unordered_map<IAStarNode*, IAStarNode*>& CameFrom, IAStarNode* CurrentNode);
	bool FindPath(IAStarNode* Start, IAStarNode* Goal, std::vector<IAStarNode*>& OutPath);
	float GetDistance(IAStarNode* FromNode, IAStarNode* ToNode);
private:

	IAStarNode* GetCheapestWeightedNode(const std::unordered_set<IAStarNode*>& OpenSet, const std::unordered_map<IAStarNode*, float>& WeightedPathScore) const;

	THeuristicFunctor Heuristic;
};

#include "AStar.inl"
