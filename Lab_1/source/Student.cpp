#include "../include/Student.h"

Student::Student()
{
	age = 0;
	GPA = 0.0f;
}

Student::Student(int _age, float _GPA)
	: age(_age), GPA(_GPA) {}

Student::Student(const Student& copy)
	: age(copy.age), GPA(copy.GPA) {}

Student::~Student() {}

Student Student::operator + (const Student& add)
{
	Student result;
	result.age = age + add.age;
	result.GPA = GPA + add.GPA;
	return result;
}

int Student::getAge() const
{
	return age;
}

void Student::setAge(int value)
{
	age = value;
}

float Student::getGPA() const
{
	return GPA;
}

void Student::setGPA(float value)
{
	GPA = value;
}

