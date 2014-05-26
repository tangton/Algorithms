#include "CppUnitTest.h"
#include "GraphNode.h"
#include "GraphSearch.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace algorithms;

namespace UnitTest
{
	TEST_CLASS(GraphSearchTest)
	{
	public:

		TEST_METHOD(TestBreadthFirstSearch)
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

			Assert::IsTrue(breadthFirstSearchResult.size() == 8);
			Assert::IsTrue(breadthFirstSearchResult.at(0) == 1);
			Assert::IsTrue(breadthFirstSearchResult.at(1) == 2);
			Assert::IsTrue(breadthFirstSearchResult.at(2) == 4);
			Assert::IsTrue(breadthFirstSearchResult.at(3) == 7);
			Assert::IsTrue(breadthFirstSearchResult.at(4) == 5);
			Assert::IsTrue(breadthFirstSearchResult.at(5) == 6);
			Assert::IsTrue(breadthFirstSearchResult.at(6) == 3);
			Assert::IsTrue(breadthFirstSearchResult.at(7) == 8);
		}

		TEST_METHOD(TestDeepthFirstSearch)
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

			vector<int> deepthFirstSearchResult = GraphSearch::RunDepthFirstSearch(graphNode1);

			Assert::IsTrue(deepthFirstSearchResult.size() == 8);
			Assert::IsTrue(deepthFirstSearchResult.at(0) == 1);
			Assert::IsTrue(deepthFirstSearchResult.at(1) == 2);
			Assert::IsTrue(deepthFirstSearchResult.at(2) == 5);
			Assert::IsTrue(deepthFirstSearchResult.at(3) == 7);
			Assert::IsTrue(deepthFirstSearchResult.at(4) == 6);
			Assert::IsTrue(deepthFirstSearchResult.at(5) == 3);
			Assert::IsTrue(deepthFirstSearchResult.at(6) == 8);
			Assert::IsTrue(deepthFirstSearchResult.at(7) == 4);
		}
	};
}