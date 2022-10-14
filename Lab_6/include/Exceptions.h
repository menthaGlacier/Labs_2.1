#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include "pch.h"

class Exception
{
public:
	Exception() : str(nullptr) {}

	Exception(const char* _str) : str(_str) {}

	void what()
	{
		if (str) { std::cout << "\n\n" << str << "\n\n"; }
	}
protected:
		const char* str;
};

class FileClosedExc : public Exception
{
public:
	FileClosedExc() : Exception("[ERROR] File isn't open.") {}
};

class NoFileModeExc : public Exception
{
public:
	NoFileModeExc() : Exception("[ERROR] No file mode specified.") {}
};

class NoFileTypeExc : public Exception
{
public:
	NoFileTypeExc() : Exception("[ERROR] No file type specified.") {}
};

class InvalidFileModeExc : public Exception
{
public:
	InvalidFileModeExc() : Exception("[ERROR] Invalid file mode.") {}
};

class InvalidFileTypeExc : public Exception
{
public:
	InvalidFileTypeExc() : Exception("[ERROR] Invalid file type.") {}
};
#endif /* EXCEPTIONS_H */
