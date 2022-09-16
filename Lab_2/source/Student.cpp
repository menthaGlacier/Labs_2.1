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
	if (this == &student) { return *this; }
	name = student.name;
	age = student.age;
	GPA = student.GPA;
	return *this;
}

Student Student::operator+(const Student& add) const
{
	return Student(name + add.name, age + add.age, 
		(GPA + add.GPA) / 2.0f); 
}

Student Student::operator+(const String& add) const
{
	return Student(name + add, age, GPA);
}

Student Student::operator+(int add) const
{
	return Student(name, age + add, GPA);
}

Student Student::operator+(float add) const
{
	return Student(name, age, GPA + add);
}

Student operator-(const Student& base, const Student& low)
{
	if ((base.GPA - low.GPA) < 0)
	{
		return Student(base.name - low.name, 
			base.age - low.age, 0.0f);
	}

	return Student(base.name - low.name, base.age - low.age,
		base.GPA - low.GPA);
}

Student operator-(const Student& base, const String& low)
{
	return Student(base.name - low, base.age, base.GPA);
}

Student operator-(const Student& base, int low)
{
	return Student(base.name, base.age - low, base.GPA);
}

Student operator-(const Student& base, float low)
{
	if (base.GPA - low < 0)
	{
		return Student(base.name, base.age, 0.0f);
	}

	return Student(base.name, base.age, base.GPA - low);
}

Student& Student::operator++()
{	
	++age;
	return *this;
}

Student Student::operator++(int)
{
	Student temp(*this);
	++(*this);
	return temp;
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
