#include <iostream>
#include "University.h"

using namespace std;

void PrintHighest(University** unis, int size)
{
	University* BestUni = NULL;
	float maxAvgSuccess = -1;

	for (int i = 0; i < size; i++)
	{
		if (unis[i]->CalcAverageSuccess() > maxAvgSuccess)
		{
			maxAvgSuccess = unis[i]->CalcAverageSuccess();
			BestUni = unis[i];
		}
	}

	cout << "College with highest Average Success Rate: " << endl;
	BestUni->PrintInfo();
}
/*
	In main, I will do exactly as required in the lab pdf, won't be declaring or 
	implementing any new fucntions so there's nothing to explain here.
*/
int main()
{
	University U1;
	University* PU2 = new University;
	University* PU3 = new University;

	U1.AddOneCollege();
	U1.AddOneCollege();

	PU2->AddOneCollege();
	PU2->AddOneCollege();
	PU2->AddOneCollege();

	PU3->AddOneCollege();
	PU3->AddOneCollege();

	for (int i = 0; i < 2; i++)
	{
		//collegeRemoved is TRUE if college has been found and removed
		bool removed = PU2->RemoveCollege();
		if (removed)
		{
			cout << "College was found and has been removed" << endl;
		}
		else
		{
			cout << "College was not found" << endl;
		}
	}

	cout << "Best College of U1 is: " << endl;
	U1.PrintBestCollege();

	cout << "Best College of PU2 is: " << endl;
	PU2->PrintBestCollege();

	
	University* unis[3] = {&U1, PU2, PU3};

	PrintHighest(unis, 3);

	delete PU2;
	delete PU3;

	system("pause");
	return 0;
}