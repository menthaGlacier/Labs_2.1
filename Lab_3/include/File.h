#ifndef FILE_H
#define FILE_H

#include "pch.h"
#include "Student.h"

enum class FlMode
{
	None = 0,
	Read = 1,
	Write = 2,
	ReadWrite = 3
};

enum class FlType
{
	None = 0,
	Binary = 1,
	Text = 2
};

class File
{
public:
	File();
	~File();

	bool isOpen() const;

	void open(FlMode mode, FlType type);
	void close();

	std::fstream& getFl();
	FlMode getMode() const;
	FlType getType() const;

private:
	std::fstream fl;
	FlMode mode;
	FlType type;
};

File& operator<<(File& file, Student& student);

#endif /* FILE_H */
