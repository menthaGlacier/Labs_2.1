#ifndef STUDENT_H
#define STUDENT_H

#include "pch.h"
#include "String.h"

class Student
{
public:
	Student();
	Student(String _name, int _age, float _GPA);
	Student(const Student&);
	~Student();

	Student operator + (const Student&);

	String getName() const;
	void setName(String str);

	int getAge() const;
	void setAge(int value);

	float getGPA() const;
	void setGPA(float value);

private:
	String name;
	int age;
	float GPA;
};

#endif /* STUDENT_H */

