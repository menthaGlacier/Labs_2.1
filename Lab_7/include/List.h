#ifndef TEMPLATE_LIST_H
#define TEMPLATE_LIST_H

#include "pch.h"

template < class T >
class List
{
public:
	List()
		: prev{ this }, next{ this }, data{} {}

	List(const T& _data)
		: prev{ this }, next{ this }, data{ _data } {}
	
	~List()
	{
		if (next == nullptr || next == this) { return; }
		
		while ( next != this )
		{	
			List* pointer{ next };

			next = pointer->next;
			next->prev = this;

			pointer->next = nullptr;
			pointer->prev = nullptr;

			delete pointer;
		}
	}

	List& findNode(int index = 0)
	{
		List* pointer{ this };

		for ( int i{ 0 }; i != index;)
		{
			if ( i < index )
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

	List& insertNode(const T& new_data, int index = 0)
	{
		List* place{ &findNode(index) }, *new_node{ nullptr };
		
		new_node = new List<T> { new_data };
		
		new_node->next = place;
		new_node->prev = place->prev;
		place->prev->next = new_node;
		place->prev = new_node;

		return *new_node;
	}

	void print(bool reverse = false)
	{
		List* pointer{ this };

		std::cout << "[cycle]";

		do
		{
			std::cout << "->" << pointer->data;
			pointer = reverse ? pointer->prev : pointer->next;
		} while ( pointer != this );

		std::cout << "->[cycle]";
	}

	List& nextNode()
	{
		return *next;
	}

	List& prevNode()
	{
		return *prev;
	}
	
public:
	T data;
private:
	List* prev, *next;
};
#endif
