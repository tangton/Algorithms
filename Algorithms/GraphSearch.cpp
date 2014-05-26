#include "GraphSearch.h"
#include <iostream>
#include <map>
#include <queue>
#include <stack>

using namespace algorithms;
using namespace std;

vector<int> GraphSearch::RunBreadthFirstSearch(const shared_ptr<GraphNode>& graphNode)
{
	vector<int> breadthFirstSearchTraverse;

	queue<const std::shared_ptr<GraphNode>> bfsQueue;
	map<int, std::shared_ptr<GraphNode>> vistedNodes;

	vistedNodes[graphNode->GetValue()] =  graphNode;
	breadthFirstSearchTraverse.push_back(graphNode->GetValue());
	bfsQueue.push(graphNode);

	while (!bfsQueue.empty())
	{
		shared_ptr<GraphNode> nextToProcess = bfsQueue.front();
		bfsQueue.pop();

		for (size_t i = 0; i < nextToProcess->GetRelationships().size(); i++)
		{
			shared_ptr<GraphNode> linkedGraphNode = nextToProcess->GetRelationships().at(i);

			if (vistedNodes.count(linkedGraphNode->GetValue()) == 0)
			{
				bfsQueue.push(linkedGraphNode);
				vistedNodes[linkedGraphNode->GetValue()] = linkedGraphNode;
				breadthFirstSearchTraverse.push_back(linkedGraphNode->GetValue());
			}
		}
	}

	return breadthFirstSearchTraverse;
}

vector<int> GraphSearch::RunDepthFirstSearch(const shared_ptr<GraphNode>& graphNode)
{
	vector<int> deepthFirstSearchTraverse;

	stack<const std::shared_ptr<GraphNode>> dfsStack;
	map<int, std::shared_ptr<GraphNode>> vistedNodes;

	vistedNodes[graphNode->GetValue()] = graphNode;
	deepthFirstSearchTraverse.push_back(graphNode->GetValue());
	dfsStack.push(graphNode);

	while (!dfsStack.empty())
	{
		shared_ptr<GraphNode> nextToProcess = dfsStack.top();

		bool allRelationshipsVisited = true;
		for (size_t i = 0; i < nextToProcess->GetRelationships().size(); i++)
		{
			shared_ptr<GraphNode> linkedGraphNode = nextToProcess->GetRelationships().at(i);

			if (vistedNodes.count(linkedGraphNode->GetValue()) == 0)
			{
				allRelationshipsVisited = false;
				dfsStack.push(linkedGraphNode);
				vistedNodes[linkedGraphNode->GetValue()] = linkedGraphNode;
				deepthFirstSearchTraverse.push_back(linkedGraphNode->GetValue());

				break;
			}

			if (allRelationshipsVisited && i == nextToProcess->GetRelationships().size() - 1)
			{
				dfsStack.pop();
				break;
			}
		}
	}

	return deepthFirstSearchTraverse;
}