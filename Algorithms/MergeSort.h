#pragma once

#include <vector>
#include <iostream>

namespace algorithms
{
	class MergeSort
	{
	private:
		static std::vector<int> Sort(const std::vector<int>& vectorToSortLeft, const std::vector<int>& vectorToSortRight);
	public:
		static std::vector<int> Sort(const std::vector<int>& vectorToSort);
	};
}