#ifndef FILE_H
#define FILE_H

#include "pch.h"
#include "Student.h"
#include "Exceptions.h"

enum class FlMode
{
	None = 0,
	Read = 1,
	Write = 2
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
	
	friend File& operator<<(File& file, const Student& student);
	friend File& operator<<(File& file, const String& str);
	friend File& operator>>(File& file, Student& student);
	friend File& operator>>(File& file, String& str);

private:
	std::fstream fl;
	FlMode mode;
	FlType type;
};

#endif /* FILE_H */
