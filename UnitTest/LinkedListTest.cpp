#include "CppUnitTest.h"
#include "LinkedListNode.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace algorithms;

namespace UnitTest
{
	TEST_CLASS(LinkedListTest)
	{
	public:

		TEST_METHOD(TestLinkedList)
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
			int value = 1;

			while (node != nullptr)
			{
				Assert::IsTrue(node->GetValue() == value);

				node = node->GetNext();
				value++;
			}
		}

		TEST_METHOD(TestReverseLinkedList)
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

			shared_ptr<LinkedListNode> node = LinkedListNode::ReverseLinkedList(node1);

			int value = 5;

			while (node != nullptr)
			{
				Assert::IsTrue(node->GetValue() == value);

				node = node->GetNext();
				value--;
			}
		}

		TEST_METHOD(TestLinkedListDeleteNode)
		{
			shared_ptr<LinkedListNode> node1 = make_shared<LinkedListNode>(1);
			shared_ptr<LinkedListNode> node2 = make_shared<LinkedListNode>(2);
			shared_ptr<LinkedListNode> node3 = make_shared<LinkedListNode>(3);
			shared_ptr<LinkedListNode> node3a = make_shared<LinkedListNode>(3);
			shared_ptr<LinkedListNode> node4 = make_shared<LinkedListNode>(4);
			shared_ptr<LinkedListNode> node5 = make_shared<LinkedListNode>(5);

			node1->SetNext(node2);
			node2->SetNext(node3);
			node3->SetNext(node3a);
			node3a->SetNext(node4);
			node4->SetNext(node5);

			shared_ptr<LinkedListNode> node = LinkedListNode::DeleteNode(node1, 1);
			while (node != nullptr)
			{
				Assert::IsTrue(node->GetValue() != 1);

				node = node->GetNext();
			}

			node = LinkedListNode::DeleteNode(node, 3);
			while (node != nullptr)
			{
				Assert::IsTrue(node->GetValue() != 3);

				node = node->GetNext();
			}
		}
	};
}