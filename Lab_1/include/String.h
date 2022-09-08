#ifndef STRING_H
#define STRING_H

#include "pch.h"

class String
{
public:
	String();
	String(char* c_str);
	String(char* _string, size_t _size);
	String(const String& str);
	~String();

	char& operator[](size_t index);
	bool operator==(const String& str);

	String& operator=(const String& str);
	
	String operator+(const String& str) const;
	String& operator+=(const String& str);

	friend std::ostream& operator<<(std::ostream& out, String& str);
	
	bool isEmpty() { return !size; }
	size_t length() { return size; }

private:
	void copystr(char* from, char* to, size_t amount);	
	
	char* string;
	size_t size;
};

#endif /* STRING_H */

