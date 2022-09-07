#pragma once

#include "pch.h"

class String
{
public:
	String();
	String(char* c_str);
	String(char* _string, size_t _size);
	String(String& str);
	~String();

	char& operator[](size_t index);
	bool operator==(String& str);

	String& operator=(String& str);
	
	String operator+(String& str);
	String& operator+=(String& str);

	friend std::ostream& operator<<(std::ostream& out, String& str);
	
	bool isEmpty() { return !size; }
	size_t length() { return size; }
private:
	void copystr(char* from, char* to, size_t amount);	
	
	char* string;
	size_t size;
	
};
