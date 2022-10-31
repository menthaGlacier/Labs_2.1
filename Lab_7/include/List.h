#ifndef TEMPLATE_LIST_H
#define TEMPLATE_LIST_H

#include "pch.h"
#include "ListNode.h"

template <class T>
class List
{
public:
	List() = delete;

	List(const T& data)
		: head(nullptr)
	{
		try
		{
			head = new ListNode<T> (data);
		}
		catch(std::bad_alloc& e)
		{
			std::cout << "\n\n" << "[ERROR] Allocation failed:"
				<< e.what() << std::endl;
			exit(2);
		}
	}

	~List()
	{
		while (head->next != head)
		{
			ListNode<T>* pointer(head);
			head = head->next;
			delete pointer;
		}

		delete head;
	}

	List& nextHead()
	{
		head = head->next;
		return *this;
	}

	List& prevHead()
	{
		head = head->prev;
		return *this;
	}

	ListNode<T>& operator[](int index)
	{
		if (head == head->next) { return *head; }
		ListNode<T>* pointer(head);

		for (int i = 0; i != index;)
		{
			if (i < index)
			{
				pointer = pointer->next;
				i++;
			}

			else
			{
				pointer = pointer->prev;
				i--;
			}
		}

		return *pointer;
	}

	ListNode<T>& insertNode(const T& new_data, int index)
	{
		ListNode<T>* place(&this->operator[](index)), *new_node(nullptr);

		try
		{
			new_node = new ListNode<T>(new_data);
		}
		catch(std::bad_alloc& e)
		{
			std::cout << "\n\n" << "[ERROR] Allocation failed:"
				<< e.what() << std::endl;
			exit(2);
		}

		new_node->next = place;
		new_node->prev = place->prev;
		place->prev->next = new_node;
		place->prev = new_node;

		return *new_node;
	}

	void print(bool reverse = false)
	{
		if (reverse) { prevHead(); }
		ListNode<T>* pointer (head);

		if (reverse) { std::cout << "[rcycle]"; }
		else { std::cout << "[cycle]"; }

		do
		{
			std::cout << "->" << pointer->data;
			pointer = reverse ?	pointer->prev : pointer->next;
		} while (pointer != head);

		if (reverse) { std::cout << "->[rcycle]\n"; }
		else { std::cout << "->[cycle]\n"; }

		if (reverse) { nextHead(); }
	}

private:
	ListNode<T>* head;
};

#endif /* TEMPLATE_LIST_H */
