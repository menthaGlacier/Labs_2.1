#include "../include/Student.h"

Student::Student()
	: name(), age(0), GPA(0.0f) {}

Student::Student(String _name, int _age, float _GPA)
	: name(_name), age(_age), GPA(_GPA) {}

Student::Student(const Student& copy)
	: name(copy.name), age(copy.age), GPA(copy.GPA) {}

Student::~Student() {}

Student Student::addition(const Student& add) const
{
	return Student(name + add.name, age + add.age,
		(GPA + add.GPA) / 2.0f);
}

void Student::print()
{
	std::cout << "Name: " << name << " | ";
	std::cout << "Age : " << age << " | ";
	std::cout << "GPA: " << GPA << "\n";
}

String Student::getName() const
{
	return name; 
}

void Student::setName(const String& str)
{
	name = str;
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
