#include "../include/StudentB.h"

StudentB::StudentB()
	: Student(), sdBInt(0), sdBChar('\0') {}

StudentB::StudentB(String _name, int _age, float _GPA, int _sdBInt,
	char _sdBChar) : Student(_name, _age, _GPA), sdBInt(_sdBInt), 
	sdBChar(_sdBChar) {}

StudentB::StudentB(const StudentB& copy)
	: Student(copy), sdBInt(copy.sdBInt), sdBChar(copy.sdBChar) {}

StudentB::~StudentB() {}

StudentB StudentB::addition(const StudentB& add) const
{
	return StudentB(name + add.name, age + add.age,
		(GPA + add.GPA) / 2.0f, sdBInt + add.sdBInt, sdBChar + add.sdBChar);
}

StudentB StudentB::operator+(const StudentB& add) const
{
	return StudentB(name + add.name, age + add.age,
		(GPA + add.GPA) / 2.0f, sdBInt + add.sdBInt, sdBChar + add.sdBChar);
}

StudentB operator-(const StudentB& base, const StudentB& low)
{
	if ((base.GPA - low.GPA) < 0)
	{
		return StudentB(base.name - low.name, base.age - low.age,
			0.0f, base.sdBInt - low.sdBInt, base.sdBChar - low.sdBChar);
	}

	return StudentB(base.name - low.name, base.age - low.age,
		base.GPA - low.GPA, base.sdBInt - low.sdBInt,
		base.sdBChar - low.sdBChar);
}

StudentB& StudentB::operator=(const StudentB& student)
{
	if (this == &student) { return *this; }
	name = student.name;
	age = student.age;
	GPA = student.GPA;
	sdBInt = student.sdBInt;
	sdBChar = student.sdBChar;
	return *this;
}

StudentB::operator int() const
{
	return sdBInt;
}

StudentB::operator char() const
{
	return sdBChar;
}

void StudentB::print() const
{
	std::cout << "Name: " << name << " | ";
	std::cout << "Age: " << age << " | ";
	std::cout << "GPA: " << GPA << " | ";
	std::cout << "Int: " << sdBInt << " | ";
	std::cout << "Char: " << sdBChar << "\n";
}

std::ostream& operator<<(std::ostream& out, const StudentB& student)
{
	out << "Name: " << student.name <<
	" | " << "Age: " << student.age <<
	" | " << "GPA: " << student.GPA <<
	" | " << "Int: " << student.sdBInt <<
	" | " << "Char: " << student.sdBChar;
	return out;
}

void StudentB::setSdBInt(int _sdBInt)
{
	sdBInt = _sdBInt;
}

int StudentB::getSdBInt() const
{
	return sdBInt;
}

void StudentB::setSdBChar(char _sdBChar)
{
	sdBChar = _sdBChar;
}

char StudentB::getSdBChar() const
{
	return sdBChar;
}
