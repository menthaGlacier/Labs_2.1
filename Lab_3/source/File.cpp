#include "../include/File.h"

File::File()
	: fl(nullptr), mode(FlMode::None), type(FlType::None) {}

File::~File()
{
	fl.close();
}

bool File::isOpen() const
{
        return fl.is_open();
}


void File::open(FlMode flMode, FlType flType)
{
	if (fl.is_open()) { fl.close(); }
	if (flMode == FlMode::None || flType == FlType::None) { return; }

	if (flMode == FlMode::Read)
	{
		if (flType == FlType::Binary) { fl.open("LAB.bin", std::fstream::in | std::fstream::binary); }
		if (flType == FlType::Text) { return; }
	}

	else if (flMode == FlMode::Write)
	{       
		if (flType == FlType::Binary) { fl.open("LAB.bin", std::fstream::out | std::fstream::binary); }
		if (flType == FlType::Text) { fl.open("LAB.txt", std::fstream::out); }
	}

	mode = flMode; type = flType;
}


void File::close()
{
	fl.close();
}

File& operator<<(File& file, Student& student)
{
	if (file.mode == FlMode::None || file.mode == FlMode::Read) { return file; }
	if (file.type == FlType::None || !file.fl.is_open()) { return file; }

	if (file.type == FlType::Binary)
	{
		file.fl.write((reinterpret_cast<char*>(&student)), sizeof(Student));
	}

	if (file.type == FlType::Text)
	{
		file.fl << student.getName() << " " << student.getAge() << " " << student.getGPA() << "\n"; 
	}

	return file;
}

File& operator>>(File& file, Student& student)
{
        if (file.mode == FlMode::None || file.mode == FlMode::Write) { return file; }
        if (file.type == FlType::None || !file.fl.is_open()) { return file; }

        if (file.type == FlType::Binary)
        {
                file.fl.read((reinterpret_cast<char*>(&student)), sizeof(Student));
        }

        return file;
}
