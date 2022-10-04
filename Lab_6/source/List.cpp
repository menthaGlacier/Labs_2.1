#include "../include/List.h"

List::List()
	: head(nullptr), listSize(0) {}

List::List(Student& _head)
	: head(&_head), listSize(1)
{
	head->next = nullptr;
}

List::~List()
{
	if (!head) { return; }	
	
	Student* tail = head->next;
	while (head)
	{
		head->next = nullptr;
		tail = head->next;
		head = tail;
	}
}

bool List::isEmpty() const
{
	return !listSize;
}

size_t List::getSize() const
{
	Student* tail = head;
	size_t size = 1;
	while (tail->next)
	{
		size++;
		tail = tail->next;
	}

	return size;
}

void List::insert(Student& newStudent)
{
	newStudent.next = nullptr;
	if (!head)
	{
		head = &newStudent;
		return;
	}

	Student* tail = head;
	while (tail->next) { tail = tail->next; }	
	tail->next = &newStudent;
}

void List::insert(Student& newStudent, size_t key)
{
	if (key > listSize) { return; }
	
	Student* tail = head;
	size_t currElem = 0;
	while (currElem != key)
	{
		currElem++;
		tail = tail->next;
	}

	newStudent.next = tail->next;
	tail->next = &newStudent;
}

void List::remove()
{
	if (!head) { return; }
	if (listSize == 1)
	{
		head->next = nullptr;
		return;
	}

	Student* tail = head;
	while (tail->next->next) { tail = tail->next; }
	
	tail->next = nullptr;
}

void List::remove(size_t key)
{
	if (key > listSize) { return; }
	if (!head) { return; }
	if (listSize == 1 || key == 0)
	{
		head = head->next; 
		return;
	}

	Student* tail = head, *temp = nullptr;
	for (size_t currElem = 0; currElem + 1 != key; currElem++)
	{
		tail = tail->next;
	}
	
	temp = tail->next;
	tail->next = temp->next;
	temp->next = nullptr;
}

Student* List::find(size_t key) const
{
	if (key > listSize) { return nullptr; }

	Student* tail = head;
	size_t currElem = 0;
	while (currElem != key) { tail = tail->next; }
	return tail;
}

void List::output() const
{
	std::cout << "\nLIST:" << "\n";

	Student* tail = head;
	while (tail)
	{
		std::cout << *tail;
		tail = tail->next;
		std::cout << " TO" << "\n";
	}

	std::cout << "END OF THE LIST" << "\n";
}
