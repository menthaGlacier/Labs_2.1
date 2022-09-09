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

	char& operator[](size_t index) const;
	bool operator==(const String& str);

	String& operator=(const String& str);
	
	String operator+(const String& str) const;
	String& operator+=(const String& str);

	friend std::ostream& operator<<(std::ostream& out, const String& str);
	
	bool isEmpty() const;
	size_t getLength() const;

private:
	void copystr(char* from, char* to, size_t amount);	
	
	char* string;
	size_t size;
};

#endif /* STRING_H */

