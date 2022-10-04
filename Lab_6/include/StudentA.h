#ifndef STUDENT_A_H
#define STUDENT_A_H

#include "pch.h"
#include "Student.h"

class StudentA : public Student
{
public:
	StudentA();
	StudentA(String _name, int _age, float _GPA, bool _sdABool, char _sdAChar);
	StudentA(const StudentA& copy);
	~StudentA();

	StudentA addition(const StudentA& add) const;
	StudentA operator+(const StudentA& add) const;
	friend StudentA operator-(const StudentA& base, const StudentA& low);
	StudentA& operator=(const StudentA& student);

	explicit operator bool() const;
	explicit operator char() const;

	void print() const override;
	friend std::ostream& operator<<(std::ostream& out, const StudentA& student);

	void setSdABool(bool _sdABool);
	bool getSdABool() const;

	void setSdAChar(char _sdAChar);
	char getSdAChar() const;

private:
	bool sdABool;
	char sdAChar;
};

#endif /* STUDENT_A_H */
