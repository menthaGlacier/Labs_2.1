#include "../include/pch.h"
#include "../include/Student.h"
#include "../include/File.h"

int main()
{
	/* Testing constructors */
	Student student_1("Armyboy", 17, 3.2f);
	Student student_2(student_1);

	/* Testing setters */
	student_1.setName("Carl");
	student_1.setAge(19);
	student_1.setGPA(4.7f);

	/* Testing summing and subtracting */
	Student result_1 = student_1 + student_2;
	Student result_2 = student_1 - student_2;

	/* Testing output */
	std::cout << student_1 << "\n";
	std::cout << student_2 << "\n";
	std::cout << result_1 << "\n";
	std::cout << result_2 << "\n\n";

	/* Testing addition */
	student_1 = student_1 + "os";
	student_1 = student_1 + 5;
	student_1 = student_1 + 0.3f;
	
	/* Testing subtraction */
	result_1 = result_1 - "ok"; 
	result_1 = result_1 - 7;
	result_1 = result_1 - 0.2f;

	/* Testing casting */
	std::cout << "Cast to String: " << static_cast<String>(student_1) << "\n";
	std::cout << "Cast to int: " << static_cast<int>(student_1) << "\n";
	std::cout << "Cast to float: " << static_cast<float>(student_1) << "\n\n";

	/* Testing assignment */
	student_2 = result_2;

	/* Testing increments */
	++student_2;
	result_2++;

	/* Checking results */
    std::cout << student_1 << "\n";
	std::cout << student_2 << "\n";
	std::cout << result_1 << "\n";
	std::cout << result_2 << "\n\n";

	/* Testing writing in files */
	File fileBin, fileText;
	fileBin.open(FlMode::Write, FlType::Binary);
	fileText.open(FlMode::Write, FlType::Text);
	fileBin << student_1;
	fileText << student_1;
	fileBin.close();
	fileText.close();

	/* Testing reading from a file */
	fileBin.open(FlMode::Read, FlType::Binary);
	fileBin >> result_2;
	std::cout << result_2 << "\n\n";

	return 0;
}
