#include "GraphNode.h"

using namespace algorithms;
using namespace std;

int GraphNode::GetValue()
{
	return _value;
}

vector<shared_ptr<GraphNode>> GraphNode::GetRelationships()
{
	return _relationships;
}

void GraphNode::AddRelationship(shared_ptr<GraphNode> graphNode)
{
	_relationships.push_back(graphNode);
}