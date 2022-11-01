#include "../include/pch.h"
#include "../include/Student.h"
#include "../include/StudentA.h"
#include "../include/StudentB.h"
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

	/* Testing derived class StudentA */
	StudentA studentA_1;
	StudentA studentA_2("Anton", 22, 4.2f, true, 'Q');
	StudentA resultA_1(studentA_2);
	StudentA resultA_2 = studentA_2 - StudentA("Ben", 3, 5.0f, true, '0');

	studentA_1.print();
	studentA_2.print();
	std::cout << resultA_1 << "\n" << resultA_2 << "\n\n";

	/* Testing derived class StudentB */
	StudentB studentB_1;
	StudentB studentB_2("Yar", 33, 3.9f, 77, '+');
	StudentB resultB_1(studentB_2);
	StudentB resultB_2 = studentB_2 + resultB_1;

	studentB_1.setName("Test");
	studentB_1.setSdBChar('#');

	studentB_1.print();
	studentB_2.print();
	std::cout << resultB_1 << "\n" << resultB_2 << "\n\n";
	std::cout << "Cast to int: " << static_cast<int>(studentB_2) << "\n";

	/* Testing virtual method */
	Student* studPtr = &studentB_1;
	studPtr->print();

	return 0;
}
