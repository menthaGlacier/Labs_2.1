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
	Student operator+(const Student& add) const;

	friend Student operator-(const Student& base, const Student& low);

	Student& operator=(const Student& student);
	
	Student& operator++();
	Student operator++(int);

	explicit operator String() const;
	explicit operator int() const;
	explicit operator float() const;

	void print() const;
	friend std::ostream& operator<<(std::ostream& out, const Student& student);

	String getName() const;
	void setName(const String& _name);

	int getAge() const;
	void setAge(int _age);

	float getGPA() const;
	void setGPA(float _GPA);

protected:
	String name;
	int age;
	float GPA;
};

#endif /* STUDENT_H */
