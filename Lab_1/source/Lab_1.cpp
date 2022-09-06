#include "../include/pch.h"
#include "../include/Student.h"

int main()
{
	Student student;

	student.setAge(19);
	student.setGPA(4.7f);

	std::cout << "Student" << '\n';
	std::cout << "Age: " << student.getAge() << '\n';
	std::cout << "GPA: " << student.getGPA() << '\n';
	return 0;
}

