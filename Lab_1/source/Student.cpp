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
	Student result(*this);
	result.name += add.name;
	result.age += add.age;
	result.GPA += add.GPA;
	return result;
}

std::ostream& operator<<(std::ostream& out, const Student& student)
{
        out << "Name: " << student.name <<
                " | Age: " << student.age <<
                " | GPA: " << student.GPA;
        return out;
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
