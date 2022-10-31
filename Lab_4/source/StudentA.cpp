#include "../include/StudentA.h"

StudentA::StudentA()
	: Student(), sdABool(false), sdAChar('\0') {}

StudentA::StudentA(String _name, int _age, float _GPA, bool _sdABool,
	char _sdAChar) : Student(_name, _age, _GPA), sdABool(_sdABool),
	sdAChar(_sdAChar) {}

StudentA::StudentA(const StudentA& copy)
	: Student(copy), sdABool(copy.sdABool), sdAChar(copy.sdAChar) {}

StudentA::~StudentA() {}

StudentA StudentA::addition(const StudentA& add) const
{
	return StudentA(name + add.name, age + add.age,
		(GPA + add.GPA) / 2.0f, sdABool + add.sdABool, sdAChar + add.sdAChar);
}

StudentA StudentA::operator+(const StudentA& add) const
{
	return StudentA(name + add.name, age + add.age,
		(GPA + add.GPA) / 2.0f, sdABool + add.sdABool, sdAChar + add.sdAChar);
}

StudentA operator-(const StudentA& base, const StudentA& low)
{
	if ((base.GPA - low.GPA) < 0)
	{
		return StudentA(base.name - low.name, base.age - low.age,
			0.0f, base.sdABool - low.sdABool, base.sdAChar - low.sdAChar);
	}

	return StudentA(base.name - low.name, base.age - low.age,
		base.GPA - low.GPA, base.sdABool - low.sdABool,
		base.sdAChar - low.sdAChar);
}

StudentA& StudentA::operator=(const StudentA& student)
{
	if (this == &student) { return *this; }
	name = student.name;
	age = student.age;
	GPA = student.GPA;
	sdABool = student.sdABool;
	sdAChar = student.sdAChar;
	return *this;
}

StudentA::operator bool() const
{
	return sdABool;
}

StudentA::operator char() const
{
	return sdAChar;
}

void StudentA::print() const
{
	std::cout << "Name: " << name << " | ";
	std::cout << "Age: " << age << " | ";
	std::cout << "GPA: " << GPA << " | ";
	std::cout << "Bool: " << sdABool << " | ";
	std::cout << "Char: " << sdAChar << "\n";
}

std::ostream& operator<<(std::ostream& out, const StudentA& student)
{
	out << "Name: " << student.name <<
	" | " << "Age: " << student.age <<
	" | " << "GPA: " << student.GPA <<
	" | " << "Bool: " << student.sdABool <<
	" | " << "Char: " << student.sdAChar;
	return out;
}

void StudentA::setSdABool(bool _sdABool)
{
	sdABool = _sdABool;
}

bool StudentA::getSdABool() const
{
	return sdABool;
}

void StudentA::setSdAChar(char _sdAChar)
{
	sdAChar = _sdAChar;
}

char StudentA::getSdAChar() const
{
	return sdAChar;
}
