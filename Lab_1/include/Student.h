#ifndef STUDENT_H
#define STUDENT_H

#include "pch.h"
#include "String.h"

class Student
{
public:
	Student();
	Student(String _name, int _age, float _GPA);
	Student(const Student& copy);
	~Student();

	Student addition(const Student& add) const;

	void print() const;

	String getName() const;
	void setName(const String& _name);

	int getAge() const;
	void setAge(int _age);

	float getGPA() const;
	void setGPA(float _GPA);

private:
	String name;
	int age;
	float GPA;
};

#endif /* STUDENT_H */
