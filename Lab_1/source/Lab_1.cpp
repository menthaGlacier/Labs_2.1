#include "../include/pch.h"
#include "../include/Student.h"

int main()
{
	/* Testing constructors */
	Student student_1;
	Student student_2("Armyboy", 17, 3.2f);
	Student result_1(student_2);

	/* Testing setters */
	student_1.setName("Carl");
	student_1.setAge(19);
	student_1.setGPA(4.7f);

	/* Testing summing */
	Student result_2 = student_1.addition(student_2);

	/* Testing output */
	student_1.print();
	student_2.print();
	result_1.print();
	result_2.print();

	return 0;
}
