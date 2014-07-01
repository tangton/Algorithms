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
#include "LinkedListNode.h"

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

void RunSortingAlgorithms()
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
}

void RunGraphAlgorithms()
{
	shared_ptr<GraphNode> graphNode1 = make_shared<GraphNode>(1);
	shared_ptr<GraphNode> graphNode2 = make_shared<GraphNode>(2);
	shared_ptr<GraphNode> graphNode3 = make_shared<GraphNode>(3);
	shared_ptr<GraphNode> graphNode4 = make_shared<GraphNode>(4);
	shared_ptr<GraphNode> graphNode5 = make_shared<GraphNode>(5);
	shared_ptr<GraphNode> graphNode6 = make_shared<GraphNode>(6);
	shared_ptr<GraphNode> graphNode7 = make_shared<GraphNode>(7);
	shared_ptr<GraphNode> graphNode8 = make_shared<GraphNode>(8);

	graphNode1->AddRelationship(graphNode2);
	graphNode1->AddRelationship(graphNode4);
	graphNode1->AddRelationship(graphNode7);

	graphNode2->AddRelationship(graphNode5);
	graphNode2->AddRelationship(graphNode6);

	graphNode3->AddRelationship(graphNode6);
	graphNode3->AddRelationship(graphNode8);

	graphNode4->AddRelationship(graphNode1);
	graphNode4->AddRelationship(graphNode6);

	graphNode5->AddRelationship(graphNode2);
	graphNode5->AddRelationship(graphNode7);

	graphNode6->AddRelationship(graphNode2);
	graphNode6->AddRelationship(graphNode3);
	graphNode6->AddRelationship(graphNode4);

	graphNode7->AddRelationship(graphNode1);
	graphNode7->AddRelationship(graphNode5);

	graphNode8->AddRelationship(graphNode3);

	vector<int> breadthFirstSearchResult = GraphSearch::RunBreadthFirstSearch(graphNode1);
	printToConsole(breadthFirstSearchResult, "Breadth First Search");

	vector<int> deepthFirstSearchResult = GraphSearch::RunDepthFirstSearch(graphNode1);
	printToConsole(deepthFirstSearchResult, "Deepth First Search");
}

void RunLinkedListAlgorithms()
{
	shared_ptr<LinkedListNode> node1 = make_shared<LinkedListNode>(1);
	shared_ptr<LinkedListNode> node2 = make_shared<LinkedListNode>(2);
	shared_ptr<LinkedListNode> node3 = make_shared<LinkedListNode>(3);
	shared_ptr<LinkedListNode> node4 = make_shared<LinkedListNode>(4);
	shared_ptr<LinkedListNode> node5 = make_shared<LinkedListNode>(5);

	node1->SetNext(node2);
	node2->SetNext(node3);
	node3->SetNext(node4);
	node4->SetNext(node5);

	shared_ptr<LinkedListNode> node = node1;
	string contents;

	cout << "Linked List" << endl;
	while (node != nullptr)
	{
		contents.append(to_string(node->GetValue()));
		contents.append(", ");

		node = node->GetNext();
	}

	contents.erase(contents.length() - 2);
	cout << contents << endl << endl;

	node = LinkedListNode::ReverseLinkedList(node1);

	cout << "Linked List Reversed" << endl;
	contents.clear();
	while (node != nullptr)
	{
		contents.append(to_string(node->GetValue()));
		contents.append(", ");

		node = node->GetNext();
	}

	contents.erase(contents.length() - 2);
	cout << contents << endl << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	RunSortingAlgorithms();
	RunGraphAlgorithms();
	RunLinkedListAlgorithms();

	return 0;
}

