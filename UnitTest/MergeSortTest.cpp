#include "CppUnitTest.h"
#include "MergeSort.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace algorithms;

namespace UnitTest
{
	TEST_CLASS(MergeSortTest)
	{
	public:

		TEST_METHOD(TestMergeSort)
		{
			vector<int> vectorToSort;
			vectorToSort.push_back(1);
			vectorToSort.push_back(9);
			vectorToSort.push_back(3);
			vectorToSort.push_back(11);
			vectorToSort.push_back(5);
			vectorToSort.push_back(1);
			vectorToSort.push_back(14);

			vector<int> selectionSortSortedVector = MergeSort::Sort(vectorToSort);

			Assert::IsTrue(selectionSortSortedVector.size() == 7);
			Assert::IsTrue(selectionSortSortedVector.at(0) == 1);
			Assert::IsTrue(selectionSortSortedVector.at(1) == 1);
			Assert::IsTrue(selectionSortSortedVector.at(2) == 3);
			Assert::IsTrue(selectionSortSortedVector.at(3) == 5);
			Assert::IsTrue(selectionSortSortedVector.at(4) == 9);
			Assert::IsTrue(selectionSortSortedVector.at(5) == 11);
			Assert::IsTrue(selectionSortSortedVector.at(6) == 14);
		}

	};
}