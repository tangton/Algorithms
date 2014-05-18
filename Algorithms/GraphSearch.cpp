#include "GraphSearch.h"
#include <iostream>
#include <map>

using namespace algorithms;
using namespace std;

vector<int> GraphSearch::RunBreadthFirstSearch(const shared_ptr<GraphNode>& graphNode)
{
	vector<int> breadthFirstSearch;

	queue<const std::shared_ptr<GraphNode>> bfsQueue;
	map<int, std::shared_ptr<GraphNode>> vistedNodes;

	vistedNodes[graphNode->GetValue()] =  graphNode;
	bfsQueue.push(graphNode);

	while (!bfsQueue.empty())
	{
		shared_ptr<GraphNode> nextToProcess = bfsQueue.front();
		bfsQueue.pop();

		breadthFirstSearch.push_back(nextToProcess->GetValue());

		for (size_t i = 0; i < nextToProcess->GetRelationships().size(); i++)
		{
			shared_ptr<GraphNode> linkedGraphNode = nextToProcess->GetRelationships().at(i);

			if (vistedNodes.count(linkedGraphNode->GetValue()) == 0)
			{
				bfsQueue.push(linkedGraphNode);
				vistedNodes[linkedGraphNode->GetValue()] = linkedGraphNode;
			}
		}
	}

	return breadthFirstSearch;
}