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
	try
	{
		if (_mode == FlMode::None) { NoFileModeExc e; throw e; }
		if (_type == FlType::None) { NoFileTypeExc e; throw e; }

		if (_mode == FlMode::Read)
		{
			if (_type == FlType::Binary)
			{
				fl.open("LAB.bin", std::fstream::in | std::fstream::binary);
			}

			if (_type == FlType::Text) { InvalidFileTypeExc e; throw e; }
		}
	}
	catch(Exception e)
	{
		e.what();
		exit(2);
	}

	if (_mode == FlMode::Write)
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
	try
	{
		if (!file.fl.is_open()) { FileClosedExc e; throw e; }
		if (file.mode == FlMode::None) { NoFileModeExc e; throw e; }
		if (file.type == FlType::None) { NoFileTypeExc e; throw e; }

		if (file.mode == FlMode::Read) { InvalidFileModeExc e; throw e; }
	}
	catch(Exception e)
	{
		e.what();
		exit(3);
	}

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
	try
	{
		if (!file.fl.is_open()) { FileClosedExc e; throw e; }
		if (file.mode == FlMode::None) { NoFileModeExc e; throw e; }
		if (file.type == FlType::None) { NoFileTypeExc e; throw e; }

		if (file.mode == FlMode::Read) { InvalidFileModeExc e; throw e; }
	}
	catch(Exception e)
	{
		e.what();
		exit(4);
	}

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
	try
	{
		if (!file.fl.is_open()) { FileClosedExc e; throw e; }
		if (file.mode == FlMode::None) { NoFileModeExc e; throw e; }
		if (file.type == FlType::None) { NoFileTypeExc e; throw e; }

		if (file.mode == FlMode::Write) { InvalidFileModeExc e; throw e; }
		if (file.type == FlType::Text) { InvalidFileTypeExc e; throw e; }
	}
	catch(Exception e)
	{
		e.what();
		exit(5);
	}

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
	try
	{
		if (!file.fl.is_open()) { FileClosedExc e; throw e; }
		if (file.mode == FlMode::None) { NoFileModeExc e; throw e; }
		if (file.type == FlType::None) { NoFileTypeExc e; throw e; }

		if (file.mode == FlMode::Write) { InvalidFileModeExc e; throw e; }
		if (file.type == FlType::Text) { InvalidFileTypeExc e; throw e; }
	}
	catch(Exception e)
	{
		e.what();
		exit(6);
	}

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
