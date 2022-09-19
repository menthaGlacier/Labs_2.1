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
	if (file.getMode() == FlMode::None || file.getMode() == FlMode::Read) { return file; }
	if (file.getType() == FlType::None || !file.isOpen()) { return file; }

	if (file.getType() == FlType::Binary)
	{
		file.getFl().write((reinterpret_cast<char*>(&student)), sizeof(Student));
	}

	if (file.getType() == FlType::Text)
	{
		file.getFl() << student.getName() << " " << student.getAge() << " " << student.getGPA() << "\n"; 
	}

	return file;
}

std::fstream& File::getFl()
{
	return fl;
}

FlMode File::getMode() const
{
	return mode;
}

FlType File::getType() const
{
	return type;
}
