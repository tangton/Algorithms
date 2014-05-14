#include "BinaryTreeSort.h"

using namespace std;
using namespace algorithms;

vector<int> BinaryTreeSort::Sort(const vector<int>& vectorToSort)
{
	shared_ptr<BinaryTreeNode> binaryTree = make_shared<BinaryTreeNode>();

	for (size_t i = 0; i < vectorToSort.size(); i++)
	{
		binaryTree->Insert(vectorToSort.at(i));
	}

	vector<int> sortedList;

	ReadTree(binaryTree, sortedList);

	return sortedList;
}

void BinaryTreeSort::ReadTree(const shared_ptr<BinaryTreeNode> node, vector<int>& sortedVector)
{
	shared_ptr<BinaryTreeNode> temp = node;
	if (temp == NULL)
	{
		return;
	}

	ReadTree(temp->GetLeftNode(), sortedVector);
	sortedVector.push_back(temp->GetValue());
	ReadTree(temp->GetRightNode(), sortedVector);
}