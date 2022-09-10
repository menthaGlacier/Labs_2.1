#include "../include/String.h"

String::String()
	: string{nullptr}, size{0} {}

String::String(const char* c_str)
	: string{nullptr}, size{0}
{
	if (!c_str) { return; }

	while (c_str[size] != '\0') { size++; }
	string = new char[size];
	copystr(c_str, string, size);
}

String::String(const char* _string, size_t _size)
	: string{nullptr}, size{_size}
{
	if (!_string) { return; }

	string = new char[size];
	copystr(_string, string, size);
}

String::String(const String& str)
	: string{nullptr}, size{str.size} 
{
	if (!str.string) { return; }

	string = new char[size];
	copystr(str.string, string, size);
}

String::~String()
{
	if (string) { delete[] string; }
}

char& String::operator[](size_t index) const
{
	if (index >= size) { throw "[ERROR]: Wrong string index"; }
	return string[index];
}

bool String::operator==(const String& str) const
{
	if (size != str.size) { return false; }
	for (size_t i{0}; i < size; i++)
	{
		if (string[i] != str.string[i]) { return false; }
	}

	return true;
}

String& String::operator=(const String& str)
{
	if (this == &str) { return *this; }

	delete[] string;
	size = str.size;
	if (str.string == nullptr || size == 0) 
	{
		string == nullptr;
		return *this;
	}

	string = new char[size];
	copystr(str.string, string, size);
	return *this;
}

String String::operator+(const String& str) const
{
	if (size + str.size == 0) { return String{}; }
	if (str.isEmpty()) { return *this; }
	if (isEmpty()) { return str; }

	char* new_str = new char[size + str.size];
	for (size_t i{0}; i < size || i < str.size; i++)
	{
		if (i < size) { new_str[i] = string[i]; }
		if (i < str.size) { new_str[i + size] = str.string[i]; }
	}

	return String{new_str, size + str.size};
}

String& String::operator+=(const String& str)
{
	if (str.size == 0) { return *this; }
	
	size_t old_size = size;
	size = old_size + str.size;
	char* old_string = string;
	string = new char[size];
	
	for (size_t i{0}; i < old_size || i < str.size; i++)
	{
		if (i < old_size) { string[i] = old_string[i]; }
		if (i < str.size) { string[i + old_size] = str.string[i]; }
	}

	delete[] old_string;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const String& str)
{
	for (size_t i{0}; i < str.size; i++)
	{
		out << str[i];
	}

	return out;
}

bool String::isEmpty() const
{
	return !size;
}

size_t String::getLength() const
{
	return size;
}

void String::copystr(const char* from, char* to, size_t amount)
{
	for (size_t i{0}; i < amount; i++)
	{
		to[i] = from[i];
	}
}
