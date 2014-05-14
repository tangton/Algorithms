#include "CppUnitTest.h"
#include "SelectionSort.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace algorithms;

namespace UnitTest
{		
	TEST_CLASS(SelectionSortTest)
	{
	public:
		
		TEST_METHOD(TestSelectionSort)
		{
			vector<int> vectorToSort;
			vectorToSort.push_back(1);
			vectorToSort.push_back(9);
			vectorToSort.push_back(3);
			vectorToSort.push_back(11);
			vectorToSort.push_back(5);
			vectorToSort.push_back(1);

			vector<int> selectionSortSortedVector = SelectionSort::Sort(vectorToSort);

			Assert::IsTrue(selectionSortSortedVector.size() == 6);
			Assert::IsTrue(selectionSortSortedVector.at(0) == 1);
			Assert::IsTrue(selectionSortSortedVector.at(1) == 1);
			Assert::IsTrue(selectionSortSortedVector.at(2) == 3);
			Assert::IsTrue(selectionSortSortedVector.at(3) == 5);
			Assert::IsTrue(selectionSortSortedVector.at(4) == 9);
			Assert::IsTrue(selectionSortSortedVector.at(5) == 11);
		}

	};
}