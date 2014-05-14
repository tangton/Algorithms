#pragma once

#include <vector>
#include <iostream>
#include <memory>

namespace algorithms
{
	class BinaryTreeNode
	{
	private:
		int _value;
		bool _valueSet;
		std::shared_ptr<BinaryTreeNode> _leftNode;
		std::shared_ptr<BinaryTreeNode> _rightNode;
	public:
		BinaryTreeNode();
		BinaryTreeNode(int value);
		int GetValue();
		void Insert(int value);
		std::shared_ptr<BinaryTreeNode> GetLeftNode();
		std::shared_ptr<BinaryTreeNode> GetRightNode();
	};
}