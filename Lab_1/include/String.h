#ifndef STRING_H
#define STRING_H

#include "pch.h"

class String
{
public:
	String();
	String(const char* c_str);
	String(const char* _string, size_t _size);
	String(const String& str);
	~String();

	char& operator[](size_t index) const;
<<<<<<< HEAD
	bool operator==(const String& str);
=======
	bool operator==(const String& str) const;
>>>>>>> string-fix

	String& operator=(const String& str);
	
	String operator+(const String& str) const;
	String& operator+=(const String& str);

	friend std::ostream& operator<<(std::ostream& out, const String& str);
	
<<<<<<< HEAD
	bool isEmpty() const;
	size_t getLength() const;
=======
	bool isEmpty() const { return !size; }
	size_t length() const { return size; }
>>>>>>> string-fix

private:
	void copystr(const char* from, char* to, size_t amount);	
	
	char* string;
	size_t size;
};

#endif /* STRING_H */

