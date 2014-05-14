#pragma once

#include <vector>
#include <iostream>
#include "BinaryTreeNode.h"

namespace algorithms
{
	class BinaryTreeSort
	{
	private:
		static void ReadTree(const std::shared_ptr<BinaryTreeNode> node, std::vector<int>& sortedVector);
	public:
		static std::vector<int> Sort(const std::vector<int>& vectorToSort);
	};
}