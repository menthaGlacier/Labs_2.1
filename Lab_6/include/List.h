#ifndef LIST_H
#define LIST_H

#include "pch.h"
#include "Student.h"

class List
{
public:
	List();
	List(Student& _head);
	~List();

	bool isEmpty() const;
	size_t getSize() const;

	void insert(Student& newStudent);
	void insert(Student& newStudent, size_t key);

	void remove();
	void remove(size_t key);
	
	Student* find(size_t key) const;
	void output() const;

private:
	Student* head;
	size_t listSize;
};

#endif /* LIST_H */
