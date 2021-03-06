#include "LinkedListNode.h"

using namespace std;
using namespace algorithms;

LinkedListNode::LinkedListNode(int value) : _value(value), _next(nullptr)
{

}

shared_ptr<LinkedListNode> LinkedListNode::GetNext()
{
	return _next;
}

int LinkedListNode::GetValue()
{
	return _value;
}

void LinkedListNode::SetNext(shared_ptr<LinkedListNode> nextNode)
{
	_next = nextNode;
}

shared_ptr<LinkedListNode> LinkedListNode::ReverseLinkedList(shared_ptr<LinkedListNode>& head)
{
	if (head != nullptr)
	{
		shared_ptr<LinkedListNode> previous = nullptr;
		while (head->GetNext() != nullptr)
		{
			shared_ptr<LinkedListNode> next = head->GetNext();
			head->SetNext(previous);
			previous = head;
			head = next;
		}
		head->SetNext(previous);
	}

	return head;
}

shared_ptr<LinkedListNode> LinkedListNode::DeleteNode(shared_ptr<LinkedListNode>& head, int value)
{
	shared_ptr<LinkedListNode> previous = nullptr;
	shared_ptr<LinkedListNode> current = head;

	while (current != nullptr)
	{
		if (current->GetValue() == value)
		{
			if (previous == nullptr)
			{
				head = current->GetNext();
			}
			else
			{
				previous->SetNext(current->GetNext());
			}
		}
		else
		{
			previous = current;
		}
		
		current = current->GetNext();
	}

	return head;
}