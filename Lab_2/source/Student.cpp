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

Student Student::operator+(const Student& add) const
{
	return Student(name + add.name, age + add.age, 
		(GPA + add.GPA) / 2.0f); 
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

Student& Student::operator=(const Student& student)
{
	if (this == &student) { return *this; }
	name = student.name;
	age = student.age;
	GPA = student.GPA;
	return *this;
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

Student::operator String() const
{
	return name;
}

Student::operator int() const
{
	return age;
}

Student::operator float() const
{
	return GPA;
}

void Student::print() const
{
	std::cout << "Name: " << name << " | ";
	std::cout << "Age: " << age << " | ";
	std::cout << "GPA: " << GPA << "\n";
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

void Student::setName(const String& _name)
{
	name = _name;
}

int Student::getAge() const
{
	return age;
}

void Student::setAge(int _age)
{
	age = _age;
}

float Student::getGPA() const
{
	return GPA;
}

void Student::setGPA(float _GPA)
{
	GPA = _GPA;
}
