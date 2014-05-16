#include "MergeSort.h"
#include "SelectionSort.h"

using namespace std;
using namespace algorithms;

vector<int> MergeSort::Sort(const vector<int>& vectorToSort)
{
	if (vectorToSort.size() >= 2)
	{
		size_t splitLength = vectorToSort.size() / 2;

		vector<int> vectorLeft;
		for (size_t i = 0; i < splitLength; i++)
		{
			vectorLeft.push_back(vectorToSort.at(i));
		}

		vector<int> vectorRight;
		for (size_t i = splitLength; i < vectorToSort.size(); i++)
		{
			vectorRight.push_back(vectorToSort.at(i));
		}

		vector<int> vectorLeftSorted = MergeSort::Sort(vectorLeft);
		vector<int> vectorRightSorted = MergeSort::Sort(vectorRight);

		// sort and merge
		return MergeSort::Sort(vectorLeftSorted, vectorRightSorted);
	}

	return vectorToSort;
}

vector<int> MergeSort::Sort(const vector<int>& vectorToSortLeft, const vector<int>& vectorToSortRight)
{
	vector<int> vectorSorted;
	vectorSorted.reserve(vectorToSortLeft.size() + vectorToSortRight.size());

	auto iteratorLeftVector = vectorToSortLeft.begin();
	auto iteratorRightVector = vectorToSortRight.begin();

	while (true)
	{
		if (iteratorLeftVector != vectorToSortLeft.end() && iteratorRightVector != vectorToSortRight.end())
		{
			if (*iteratorLeftVector <= *iteratorRightVector)
			{
				vectorSorted.push_back(*iteratorLeftVector);
				iteratorLeftVector++;
			}
			else
			{
				vectorSorted.push_back(*iteratorRightVector);
				iteratorRightVector++;
			}
		}
		else if (iteratorLeftVector != vectorToSortLeft.end())
		{
			vectorSorted.push_back(*iteratorLeftVector);
			iteratorLeftVector++;
		}
		else if (iteratorRightVector != vectorToSortRight.end())
		{
			vectorSorted.push_back(*iteratorRightVector);
			iteratorRightVector++;
		}
		else
		{
			break;
		}
	}

	return vectorSorted;
}