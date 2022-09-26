#ifndef STUDENT_B_H
#define STUDENT_B_H

#include "Student.h"

class StudentB : public Student
{
public:
	StudentB();
	StudentB(String _name, int _age, float _GPA, int _sdBInt, char _sdBChar);
	StudentB(const StudentB& copy);
	~StudentB();

	StudentB addition(const StudentB& add) const;
	StudentB operator+(const StudentB& add) const;
	friend StudentB operator-(const StudentB& base, const StudentB& low);
	StudentB& operator=(const StudentB& student);

	explicit operator int() const override;
	explicit operator char() const;

	void print() const override;
	friend std::ostream& operator<<(std::ostream& out, const StudentB& student);

	void setSdBInt(int _sdBInt);
	int getSdBInt() const;

	void setSdBChar(char _sdBChar);
	char getSdBChar() const;

private:
	int sdBInt;
	char sdBChar;
};

#endif /* STUDENT_B_H */
