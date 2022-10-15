#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include "pch.h"

class Exception
{
public:
	Exception()
		: errStr(nullptr) {}

	Exception(const char* _errStr)
		: errStr(_errStr) {}

	void what()
	{
		if (errStr) { std::cout << "\n\n" << errStr << "\n\n"; }
	}

protected:
	const char* errStr;
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
