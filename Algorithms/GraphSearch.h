#pragma once

#include "GraphNode.h"
#include <queue>

namespace algorithms
{
	class GraphSearch
	{
	public:
		static std::vector<int> RunBreadthFirstSearch(const std::shared_ptr<GraphNode>& graphNode);
	};
}