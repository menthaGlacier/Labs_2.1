#include "../include/Student.h"

Student::Student()
	: name(), age(0), GPA(0.0f) {}

Student::Student(String _name, int _age, float _GPA)
	: name(_name), age(_age), GPA(_GPA) {}

Student::Student(const Student& copy)
	: name(copy.name), age(copy.age), GPA(copy.GPA) {}

Student::~Student() {}

Student& Student::operator=(const Student& student)
{
	if (this == &student)
	{
		return *this;
	}

	name = student.name;
	age = student.age;
	GPA = student.GPA;
	return *this;
}

Student Student::operator+(const Student& add) const
{
	Student result;
	result.name = name + add.name;
	result.age = age + add.age;
	result.GPA = (GPA + add.GPA) / 2.0f;
	return result;
}

Student Student::operator+(const String& add) const
{
	Student result(*this);
	result.name += add;
	return result;
}

Student Student::operator+(int add) const
{
	Student result(*this);
	result.age += add;
	return result;
}

Student Student::operator+(float add) const
{
	Student result(*this);
	result.GPA += add;
	return result;
}

Student operator-(const Student& base, const Student& low)
{
        Student result;
        result.name = "TempPlaceholder";
        result.age = base.age - low.age;
        result.GPA = base.GPA - low.GPA;
        return result;
}

Student operator-(const Student& base, const String& low)
{
	/* TODO Implement this after minus operator
	overloading in the String class */
	Student result(base);
	return result;
}

Student operator-(const Student& base, int low)
{
	Student result(base);
	result.age = base.age - low;
	return result;
}

Student operator-(const Student& base, float low)
{
	Student result(base);
	result.GPA = base.GPA - low;
	return result;
}

Student::operator String()
{
	return name;
}

Student::operator int()
{
	return age;
}

Student::operator float()
{
	return GPA;
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
