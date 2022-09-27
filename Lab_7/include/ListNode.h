#ifndef TEMPLATE_LIST_NODE_H
#define TEMPLATE_LIST_NODE_H

template<class T>
class ListNode
{
public:
	ListNode()
		: data(), prev(this), next(this) {}

	ListNode(const T& _data)
		: data(_data), prev(this), next(this) {}

	~ListNode()
	{
		if (next != this)
	   	{
		   	next->prev = prev;
			prev->next = next;
	   	}
	}

	ListNode& nextNode()
	{
		return *next;
	}

	ListNode& prevNode()
	{
		return *prev;
	}
	
	template <class L>
	friend class List;

public:
	T data;
private:
	ListNode *prev, *next;
};

#endif /* TEMPLATE_LIST_NODE_H  */
