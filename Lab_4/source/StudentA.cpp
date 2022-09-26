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
