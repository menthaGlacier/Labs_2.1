#include "../include/File.h"

File::File()
	: fl(), mode(FlMode::None), type(FlType::None) {}

File::~File()
{
	fl.close();
}

bool File::isOpen() const
{
	return fl.is_open();
}

void File::open(FlMode _mode, FlType _type)
{
	if (fl.is_open()) { fl.close(); }
	if (_mode == FlMode::None || _type == FlType::None) { return; }

	if (_mode == FlMode::Read)
	{
		if (_type == FlType::Binary)
		{
			fl.open("LAB.bin", std::fstream::in | std::fstream::binary);
		}

		if (_type == FlType::Text) { return; }
	}

	else if (_mode == FlMode::Write)
	{
		if (_type == FlType::Binary)
		{
			fl.open("LAB.bin", std::fstream::out | std::fstream::binary);
		}

		if (_type == FlType::Text) { fl.open("LAB.txt", std::fstream::out); }
	}

	mode = _mode; type = _type;
}

void File::close()
{
	fl.close();
}

File& operator<<(File& file, const String& str)
{
	if (file.mode == FlMode::None || file.mode == FlMode::Read) { return file; }
	if (file.type == FlType::None || !file.fl.is_open()) { return file; }

	if (file.type == FlType::Binary)
	{
		char* string = &str[0];
		size_t length = str.getLength();

		file.fl.write(reinterpret_cast<char*>(&length), sizeof(size_t));
		if (length > 0) { file.fl.write(string, length); }
	}
	
	if (file.type == FlType::Text)
	{
		file.fl << str; 
	}

	return file;
}

File& operator<<(File& file, const Student& student)
{
	if (file.mode == FlMode::None || file.mode == FlMode::Read) { return file; }
	if (file.type == FlType::None || !file.fl.is_open()) { return file; }

	if (file.type == FlType::Binary)
	{
		int age = student.getAge();
		float GPA = student.getGPA();

		file << student.getName();
		file.fl.write(reinterpret_cast<char*>(&age), sizeof(int));
		file.fl.write(reinterpret_cast<char*>(&GPA), sizeof(float)); 
	}

	if (file.type == FlType::Text)
	{
		file.fl << student.getName() << " " << student.getAge()
			<< " " << student.getGPA() << "\n"; 
	}

	return file;
}

File& operator>>(File& file, String& str)
{
	if (file.mode == FlMode::None || file.mode == FlMode::Write) { return file; }
	if (file.type == FlType::None || !file.fl.is_open()) { return file; }
		
	if (file.type == FlType::Binary)
	{		
		char* string = &str[0];
		size_t length = 0;

		file.fl.read(reinterpret_cast<char*>(&length), sizeof(size_t));
		if (length > 0)
		{
			string = new char[length];
			file.fl.read(string, length);
		}
		
		str = String(string, length);
		delete[] string;
	}

	return file;
}

File& operator>>(File& file, Student& student)
{
	if (file.mode == FlMode::None || file.mode == FlMode::Write) { return file; }
	if (file.type == FlType::None || !file.fl.is_open()) { return file; }

	if (file.type == FlType::Binary)
	{
		String name;
		int age = 0;
		float GPA = 0.0f;
		
		file >> name;
		file.fl.read(reinterpret_cast<char*>(&age), sizeof(int));
		file.fl.read(reinterpret_cast<char*>(&GPA), sizeof(float));
		
		student.setName(name);
		student.setAge(age);
		student.setGPA(GPA);
	}

	return file;
}
