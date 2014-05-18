// AlgorithmsUI.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <tchar.h>
#include <vector>
#include <string>
#include "SelectionSort.h"
#include "BinaryTreeSort.h"
#include "MergeSort.h"
#include "GraphNode.h"
#include "GraphSearch.h"

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
	vectorToSort.push_back(11);
	vectorToSort.push_back(5);
	vectorToSort.push_back(51);
	vectorToSort.push_back(5);
	vectorToSort.push_back(11);
	vectorToSort.push_back(566);
	vectorToSort.push_back(11);
	vectorToSort.push_back(5);
	vectorToSort.push_back(112);
	vectorToSort.push_back(35);
	vectorToSort.push_back(11);
	vectorToSort.push_back(75);
	vectorToSort.push_back(11);
	vectorToSort.push_back(5);
	vectorToSort.push_back(121);
	vectorToSort.push_back(5);
	vectorToSort.push_back(311);
	vectorToSort.push_back(52);
	vectorToSort.push_back(11);
	vectorToSort.push_back(5);
	vectorToSort.push_back(1);
	printToConsole(vectorToSort, "Vector unsorted");

	vector<int> selectionSortSortedVector = SelectionSort::Sort(vectorToSort);
	printToConsole(selectionSortSortedVector, "Vector sorted by Selection Sort");

	vector<int> binaryTreeSortSortedVector = BinaryTreeSort::Sort(vectorToSort);
	printToConsole(binaryTreeSortSortedVector, "Vector sorted by Binary Tree Sort");

	vector<int> mergeSortSortedVector = MergeSort::Sort(vectorToSort);
	printToConsole(mergeSortSortedVector, "Vector sorted by Merge Sort");

	shared_ptr<GraphNode> graphNode1 = make_shared<GraphNode>(1);
	shared_ptr<GraphNode> graphNode2 = make_shared<GraphNode>(2);
	shared_ptr<GraphNode> graphNode3 = make_shared<GraphNode>(3);
	shared_ptr<GraphNode> graphNode4 = make_shared<GraphNode>(4);
	shared_ptr<GraphNode> graphNode5 = make_shared<GraphNode>(5);

	graphNode1->AddRelationship(graphNode2);
	graphNode1->AddRelationship(graphNode3);
	graphNode1->AddRelationship(graphNode4);

	graphNode2->AddRelationship(graphNode1);
	graphNode2->AddRelationship(graphNode4);

	graphNode3->AddRelationship(graphNode1);
	
	graphNode4->AddRelationship(graphNode1);
	graphNode4->AddRelationship(graphNode2);
	graphNode4->AddRelationship(graphNode5);

	graphNode5->AddRelationship(graphNode4);

	vector<int> breadthFirstSearchResult = GraphSearch::RunBreadthFirstSearch(graphNode1);
	printToConsole(breadthFirstSearchResult, "Breadth First Search");

	return 0;
}

