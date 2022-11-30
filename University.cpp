#include "University.h"
#include <iostream>

using namespace std;

University::University()
{
	Clgs = new College * [15]; //Now we allocate the array of pointers
	for (int i = 0; i < 15; i++)
	{
		 //We set all pointers in the CLGS array to Null to check later if the slot is free or occupied
		Clgs[i] = NULL;
	}
	//The university is still new and has no Colleges for the time being.
	Num = 0;
	cout << "University Contructor is called" << endl;
}

void University::AddOneCollege()
{
	//Before Adding a College I have to check if I have room in first place right?
	if (Num == 15)
	{
		cout << "Not Enough Room!";
		return;
	}
	
	//Now that we checked we have room let's get the college data from the user.
	char name;
	int stds;
	float sucPrc;
	cout << "Enter College Name: ";
	cin >> name;

	cout << "Number of Students: ";
	cin >> stds;

	cout << "College Success Percentage: ";
	cin >> sucPrc;

	College* newCollege = new College(name, stds, sucPrc);//Why do I I use a pointer here not an object?
	/*
	Try to think about this question before reading the answer as it's very IMPORTANT!
	We use the pointer to allocate the object dynamically not automatically, we all know that.
	It was necessary to allocate it dynamically here becuz automatic objects are deleted
	once you get out of the scope they were created in. So if I create a college object here 
	it will be immediately destructed once the compiler is done executing the AddOneCollege function
	having acheived nothing. CLOWN Emoji:)
	Now it will remain forever in the Clgs array (till I delete it ofc)
	*/


	//First check if the college already exists in the university
	for (int i = 0; i < 15; i++)
	{
		if (Clgs[i] != NULL && Clgs[i]->GetName() == name)
		{
			//Hey this college already exists in the array!
			cout << "College already in University" << endl;
			return;
		}
	}
	Clgs[Num++] = newCollege; //We have added the college to the array
	cout << "College Successfully Added" << endl;
	return;		
}
bool University::RemoveCollege()
{
	char name;
	cout << "Name of college to remove: ";
	cin >> name;

	for (int i = 0; i < 15; i++)
	{
		/*You may think why is it important to check if each index != Null at first ? Why don't
		we just compare if the names are the same? Well if it was null I can't make null->getname right?
		So at first I make sure that a college exists and then I compare its name with the name I want
		to be removed. Very Important trick that could crash you code!*/
		if (Clgs[i] != NULL && Clgs[i]->GetName() == name)
		{
			//The college the user wants to delete exists in the array, we delete it now.
			delete Clgs[i];
			Clgs[i] = NULL;
			--Num;
			return true;
		}
	}
	return false;
}

float University::CalcAverageSuccess()
{
	float successRate = 0;
	for (int i = 0; i < 15; i++)
	{
		if (Clgs[i] != NULL)
		successRate += Clgs[i]->GetSuccess_prc();
	}
	//Average Success rate will be sum of success rates divided by num of colleges
	return successRate / Num;
}

void University::PrintBestCollege()
{
	//We create a pointer to the best college that we'll find now.
	College* BestCollege = NULL;
	float maxSuccessPrc = -1; /*I create a very low criteria, and check if a college has
							    a better success rate will be declared as best*/

	for (int i = 0; i < 15; i++)
	{
		if (Clgs[i] != NULL && Clgs[i]->GetSuccess_prc() > maxSuccessPrc)
		{
			maxSuccessPrc = Clgs[i]->GetSuccess_prc();
			BestCollege = Clgs[i];
		}
	}
	//Printing the Best College info
	BestCollege->PrintInfo();
}

void University::PrintInfo()
{
	//print info of University
	cout << "Number of Colleges: " << Num << endl;

	//we print the info of each college
	for (int i = 0; i < 15; i++)
	{
		if (Clgs[i] != NULL)
		{
			Clgs[i]->PrintInfo();
		}
	}
}

University::~University()
{
	//We free all pointers we created in the CLGS array
	for (int i = 0; i < 15; i++)
	{
		if (Clgs[i] != NULL)
		{
			delete Clgs[i];
		}
	}

	//When I'm deleting the University, The colleges in the university will no longer exist afterwards
	//that's why the relation is Aggregation in frist place!
	delete[] Clgs;
	cout << "University Destructor is called" << endl;
}