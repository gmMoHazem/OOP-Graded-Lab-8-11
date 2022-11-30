#include "College.h"
#include <iostream>

using namespace std;

College::College(char name, int std, float sucPrc)
{
	//You can also make Name = name; but let's make use of the setters we made.
	SetName(name);
	SetStudents(std);
	SetSuccess_prc(sucPrc);
	cout << "College Constructor is called" << endl;
}

char College::GetName()
{
	return Name;
}

void College::SetName(char n)
{
	Name = n;
}

int College::GetStudents()
{
	return Students;
}

void College::SetStudents(int students)
{
	Students = students;
}

float College::GetSuccess_prc()
{
	return Success_prc;
}

void College::SetSuccess_prc(float successPrc)
{
	Success_prc = successPrc;
}

void College::ReadData()
{
	cout << "Enter College Name: ";
	cin >> Name;

	cout << "Number of Students: ";
	cin >> Students;

	cout << "College Success Percentage: ";
	cin >> Success_prc;
}

void College::PrintInfo()
{
	cout << "Name: " << Name << endl;
	cout << "Students: " << Students << endl;
	cout << "Success Percentage: " << Success_prc << endl;
}

College::~College()
{
	cout << "College Destructor is called" << endl;
}