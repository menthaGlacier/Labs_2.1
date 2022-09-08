#include "../include/pch.h"
#include "../include/Student.h"

int main()
{
	Student student_1;
	
	/* Testing setters */
	student_1.setName("Carl");
	student_1.setAge(19);
	student_1.setGPA(4.7f);

	/* Testing constructors */
	Student student_2 ("Armyboy", 17, 3.2f);

	/* Testing summing */
	Student result = student_1 + student_2;

	std::cout << "Student " << student_1.getName() << "\n";
	std::cout << "Age: " << student_1.getAge() << "\n";
	std::cout << "GPA: " << student_1.getGPA() << "\n\n";
	
	std::cout << "Student 2" << "\n";
	std::cout << "Age: " << student_2.getAge() << "\n";
	std::cout << "GPA: " << student_2.getGPA() << "\n\n";

	std::cout << "Result" << "\n";
	std::cout << "Age: " << result.getAge() << "\n";
	std::cout << "GPA: " << result.getGPA() << "\n\n";

	return 0;
}

