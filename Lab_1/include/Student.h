#ifndef STUDENT_H
#define STUDENT_H

#include "pch.h"

class Student
{
public:
	Student();
	Student(int age, float GPA);
	Student(const Student& student);
	~Student();

	int getAge() const;
	void setAge(int value);

	float getGPA() const;
	void setGPA(float value);

private:
	int age;
	float GPA;
};

#endif /* STUDENT_H */
