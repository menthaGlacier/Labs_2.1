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

/*
void File::open(FlMode flMode, FlType flType)
{
	if (fl.is_open()) { fl.close() }
	if (flMode == FlMode::None || FlType == FlType::None) { return; }

	if (flType == FlType::Binary) {	fl.open("LAB.bat"); }
	else if (flType == FlType::Text) { fl.open("Lab.txt"); }

	if (flMode == FlMode::Read) { fl.setf(std::fstream::in); }
	else if (flMode == FlMode::Write) { fl.setf(std::fstream::out); }
	else if (flMode == FlMode::ReadWrite) { fl.setf(std::fstream::in | std::fstream::out); } 

	mode = flMode; type = flType;
}
*/

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
