#pragma once

struct IAStarNode
{
	virtual std::size_t GetNumNeighbours() const = 0;
	virtual IAStarNode* GetNeighbour(std::size_t Index) const = 0;
	virtual float GetDistance(IAStarNode* OtherNode) const = 0;
};
