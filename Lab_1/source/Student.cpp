#include "../include/Student.h"

Student::Student()
{
}

Student::Student(int age, float GPA)
{
}

Student::~Student()
{
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

