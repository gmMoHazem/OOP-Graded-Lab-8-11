#pragma once
#include "College.h" //Note that we need to include College.h

class University
{
	College** Clgs;     /*Notice that I can't create an array of College objects 
						as the compiler wouldn't understand how to construct them becuz
						we didn't create a default constructor in college.h.
						The solution here is to create an array of pointers but pointers to what??
						If you said pointers to objects, then we will run into the same problem soon,
						when initalizing the pointer ===> "pointer = new College;" Again College
						has no default constructor! So we create an array of pointers to pointers
						if that makes any sense :)  
						*/

	int Num;
public:
	
	University();

	void AddOneCollege();

	bool RemoveCollege();

	float CalcAverageSuccess();

	void PrintBestCollege();

	void PrintInfo();

	~University();
};