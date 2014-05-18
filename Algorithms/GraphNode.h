#pragma once

#include <vector>
#include <memory>

namespace algorithms
{
	class GraphNode
	{
	private:
		int _value;
		std::vector<std::shared_ptr<GraphNode>> _relationships;
	public:
		GraphNode(int value) : _value(value)
		{
		}
		int GetValue();
		std::vector<std::shared_ptr<GraphNode>> GetRelationships();
		void AddRelationship(std::shared_ptr<GraphNode> graphNode);
	};
}