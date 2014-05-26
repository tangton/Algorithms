#pragma once

#include "GraphNode.h"

namespace algorithms
{
	class GraphSearch
	{
	public:
		static std::vector<int> RunBreadthFirstSearch(const std::shared_ptr<GraphNode>& graphNode);
		static std::vector<int> RunDepthFirstSearch(const std::shared_ptr<GraphNode>& graphNode);
	};
}