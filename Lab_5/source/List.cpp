#include "../include/List.h"

List::List()
	: head(), listSize(0) {}

List::List(const Student& _head)
	: head(_head), listSize(1)
{
	head.next = nullptr;
}

List::~List()
{
	if (!listSize) { return; }

	Student* tail = head.next;
	while (tail)
	{
		Student* temp = tail->next;
		delete tail;
		tail = temp;
	}
}

bool List::isEmpty() const
{
	return !listSize;
}

size_t List::getSize() const
{
	return listSize;
}

void List::insert(const Student& data)
{
	if (!listSize)
	{
		head = data;
		head.next = nullptr;
		listSize++;
		return;
	}

	Student* tail = nullptr;
	if (listSize == 1) { tail = &head; }
	else { tail = head.next; }

	while (tail->next) { tail = tail->next; }

	if (typeid(data) == typeid(Student))
	{
		tail->next = new Student(data);
	}

	else if (typeid(data) == typeid(StudentA))
	{
		tail->next = new StudentA(reinterpret_cast<const StudentA&>(data));
	}

	else if (typeid(data) == typeid(StudentB))
	{
		tail->next = new StudentB(reinterpret_cast<const StudentB&>(data));
	}

	if (!tail->next) { exit(-1); }
	tail->next->next = nullptr;
	listSize++;
}

void List::insert(const Student& data, size_t key)
{
	if (key > listSize) { return; }

	if (!listSize)
	{
		head = data;
		listSize++;
		return;
	}

	if (listSize == 0 || key == 0)
	{
		Student* tail = head.next;
		head = data;
		head.next = tail;
		listSize++;
		return;
	}

	Student* tail = &head;
	for (size_t i = 1; i < key; i++) { tail = tail->next; }

	Student* temp = tail->next;
	if (typeid(data) == typeid(Student))
	{
		tail->next = new Student(data);
	}

	else if (typeid(data) == typeid(StudentA))
	{
		tail->next = new StudentA(reinterpret_cast<const StudentA&>(data));
	}

	else if (typeid(data) == typeid(StudentB))
	{
		tail->next = new StudentB(reinterpret_cast<const StudentB&>(data));
	}

	if (!tail->next) { exit(-1); }
	tail->next->next = temp;
	listSize++;
}

void List::remove()
{
	if (!listSize) { return; }

	if (listSize == 1)
	{
		head = Student();
		listSize--;
		return;
	}

	Student* tail = head.next;
	while (tail->next->next) { tail = tail->next; }

	Student* temp = tail->next;
	tail->next = nullptr;
	delete temp;
	listSize--;
}

void List::remove(size_t key)
{
	if (!listSize || key >= listSize) { return; }

	if (listSize == 1)
	{
		head = Student();
		listSize--;
		return;
	}

	if (key == 0)
	{
		Student* temp = head.next;
		head = *(temp);
		head.next = temp->next;
		delete temp;
		listSize--;
		return;
	}

	Student* tail = nullptr;
	tail = &head;
	for (size_t i = 1; i < key; i++) { tail = tail->next; }

	Student* temp = tail->next;
	tail->next = temp->next;
	delete temp;
	listSize--;
}

const Student* List::find(size_t key) const
{
	if (key >= listSize) { return nullptr; }
	if (key == 0) { return &head; }

	Student* tail = head.next;
	for (size_t i = 1; i < key; i++) { tail = tail->next; }
	return tail;
}

void List::output() const
{
	std::cout << "LIST:" << "\n";

	if (listSize)
	{
		std::cout << head << "\n" << "TO ";
		Student* tail = head.next;
		while (tail)
		{
			tail->print();
			tail = tail->next;
			std::cout << "TO ";
		}

		std::cout << "END OF THE LIST" << "\n";
	}

	else { std::cout << "LIST IS EMPTY" << "\n"; }
}
