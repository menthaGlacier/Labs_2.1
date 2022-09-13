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
	std::cout << student_1 << "\n";
	std::cout << student_2 << "\n";
	std::cout << result << "\n\n";

	/* Testing operators overloading */
	student_1 = student_1 + "os";
	student_1 = student_1 + 5;
	student_1 = student_1 + 0.3f;
	
	std::cout << "Cast to String: " << static_cast<String>(student_1) << "\n";
	std::cout << "Cast to int: " << static_cast<int>(student_1) << "\n";
	std::cout << "Cast to float: " << static_cast<float>(student_1) << "\n";

	student_2 = result;
	result = result - student_1;

	std::cout << std::endl;

        /* Checking results */
        std::cout << student_1 << "\n";
	std::cout << student_2 << "\n";
	std::cout << result << "\n";

	return 0;
}
