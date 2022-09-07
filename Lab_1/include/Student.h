#ifndef STUDENT_H
#define STUDENT_H

#include "pch.h"

class Student
{
public:
	Student();
	Student(int _age, float _GPA);
	Student(const Student&);
	~Student();

	Student operator + (const Student&);

	int getAge() const;
	void setAge(int value);

	float getGPA() const;
	void setGPA(float value);

private:
	int age;
	float GPA;
};

#endif /* STUDENT_H */

