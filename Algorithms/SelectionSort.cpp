#include "SelectionSort.h"

using namespace std;
using namespace algorithms;

vector<int> SelectionSort::Sort(const vector<int>& vectorToSort)
{
	vector<int> sortedVector = vectorToSort;

	int tempValue;
	int indexMinValue;

	for (size_t i = 0; i < sortedVector.size(); i++)
	{
		indexMinValue = i;

		for (size_t j = i + 1; j < sortedVector.size(); j++)
		{
			if (sortedVector.at(j) < sortedVector.at(indexMinValue))
			{
				indexMinValue = j;
			}
		}

		// perform swap
		tempValue = sortedVector.at(indexMinValue);

		sortedVector.at(indexMinValue) = sortedVector.at(i);
		sortedVector.at(i) = tempValue;
	}

	return sortedVector;
}