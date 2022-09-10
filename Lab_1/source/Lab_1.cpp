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

	/* Testing output */
	std::cout << student_1 << '\n';
	std::cout << student_2 << '\n';
	std::cout << result << '\n';

	std::cout << std::endl;
	return 0;
}

