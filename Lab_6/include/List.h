#ifndef LIST_H
#define LIST_H

#include "pch.h"
#include "Student.h"
#include "StudentA.h"
#include "StudentB.h"

class List
{
public:
	List();
	List(const Student& _head);
	~List();

	bool isEmpty() const;
	size_t getSize() const;

	void insert(const Student& data);
	void insert(const Student& data, size_t key);

	void remove();
	void remove(size_t key);

	const Student* find(size_t key) const;
	void output() const;

private:
	Student head;
	size_t listSize;
};

#endif /* LIST_H */
