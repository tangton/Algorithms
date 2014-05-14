#include "BinaryTreeNode.h"

using namespace std;
using namespace algorithms;

BinaryTreeNode::BinaryTreeNode() : _value(0), _valueSet(false)
{

}

BinaryTreeNode::BinaryTreeNode(int value) : _value(value), _valueSet(true)
{

}

int BinaryTreeNode::GetValue()
{
	return _value;
}

void BinaryTreeNode::Insert(int value)
{
	if (_leftNode == NULL && _rightNode == NULL && _valueSet == false)
	{
		_value = value;
		_valueSet = true;
	}
	else if (value < _value)
	{
		if (_leftNode == NULL)
		{
			_leftNode = make_shared<BinaryTreeNode>(value);
		}
		else
		{
			_leftNode->Insert(value);
		}
	}
	else
	{
		if (_rightNode == NULL)
		{
			_rightNode = make_shared<BinaryTreeNode>(value);
		}
		else
		{
			_rightNode->Insert(value);
		}
	}
}

std::shared_ptr<BinaryTreeNode> BinaryTreeNode::GetLeftNode()
{
	return _leftNode;
}

std::shared_ptr<BinaryTreeNode> BinaryTreeNode::GetRightNode()
{
	return _rightNode;
}