#include "../include/String.h"

String::String()
	: string{nullptr}, size{0} {}

String::String(char* c_str)
	: string{c_str}, size{0}
{
	if (!c_str) { return; }

	while(c_str[size] != '\0') { size++; }
}

String::String(char* _string, size_t _size)
	: string{_string}, size{_size} {}

String::String(String& str)
	: string{str.string}, size{str.size} {}

String::~String()
{
	if (string) { delete[] string; }
}

char& String::operator[](size_t index)
{
	if (index >= size) { throw "[ERROR]: Wrong string index"; }
	return string[index];
}

bool String::operator==(String& str)
{
	if (size != str.size) { return false; }
	for(size_t i{0}; i < size; i++)
	{
		if (string[i] != str.string[i]) { return false; }
	}
	return true;
}

String& String::operator=(String& str)
{
	if (this == &str) { return *this; }

	delete[] string;

	string = str.string;
	size = str.size;
	return *this;
}

String String::operator+(String& str)
{
	if (size + str.size == 0) { String tmp{}; return tmp; }
	if (str.size == 0) { return *this; }
	if (size == 0) { return str; }

	char* new_str = new char[size + str.size];
	for(size_t i{0}; i < size || i < str.size; i++)
	{
		if (i < size) { new_str[i] = string[i]; }
		if (i < str.size) { new_str[i + size] = str.string[i]; }
	}
	String tmp{new_str, size + str.size};
	return tmp;
}

String& String::operator+=(String& str)
{
	if (str.size == 0) { return *this; }
	
	size_t old_size = size;
	size = old_size + str.size;
	char* old_string = string;
	string = new char[size];
	
	for(size_t i{0}; i < old_size || i < str.size; i++)
	{
		if (i < old_size) { string[i] = old_string[i]; }
		if (i < str.size) { string[i + old_size] = str.string[i]; }
	}
	delete[] old_string;
	return *this;
}

std::ostream& operator<<(std::ostream& out,String& str)
{
	for(size_t i{0}; i < str.size; i++)
	{
		out << str[i];
	}
	return out;
}
