// AlgorithmsUI.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <tchar.h>
#include <vector>
#include <string>
#include "SelectionSort.h"
#include "BinaryTreeSort.h"

using namespace algorithms;
using namespace std;

void printToConsole(const vector<int>& vectorToPrint, const string& title)
{
	cout << title << endl;
	string vectorContents;
	for (vector<int>::const_iterator it = vectorToPrint.begin(); it != vectorToPrint.end(); ++it)
	{
		vectorContents.append(to_string(*it));
		vectorContents.append(", ");
	}
	vectorContents.erase(vectorContents.length() - 2);
	cout << vectorContents << endl << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vectorToSort;
	vectorToSort.push_back(1);
	vectorToSort.push_back(9);
	vectorToSort.push_back(3);
	vectorToSort.push_back(11);
	vectorToSort.push_back(5);
	vectorToSort.push_back(1);
	printToConsole(vectorToSort, "Vector unsorted");

	vector<int> selectionSortSortedVector = SelectionSort::Sort(vectorToSort);
	printToConsole(selectionSortSortedVector, "Vector sorted by Selection Sort");

	vector<int> binaryTreeSortSortedVector = BinaryTreeSort::Sort(vectorToSort);
	printToConsole(binaryTreeSortSortedVector, "Vector sorted by Binary Tree Sort");

	return 0;
}

