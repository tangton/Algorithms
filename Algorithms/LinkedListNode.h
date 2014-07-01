#pragma once

#include <memory>

namespace algorithms
{
	class LinkedListNode
	{
	private:
		int _value;
		std::shared_ptr<LinkedListNode> _next;
	public:
		LinkedListNode(int value);
		std::shared_ptr<LinkedListNode> GetNext();
		int GetValue();
		void SetNext(std::shared_ptr<LinkedListNode> nextNode);

		static std::shared_ptr<LinkedListNode> ReverseLinkedList(std::shared_ptr<LinkedListNode>& head);
	};
}