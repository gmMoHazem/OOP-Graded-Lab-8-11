#pragma once
/*
	If you have any questions about the code feel free to ask me!
	Good luck :))
*/

class College {
private:
	char Name;
	int Students;
	float Success_prc;

public:
	College(char name, int students, float successPrc);
	// Creating our Getters:
	char GetName();
	int GetStudents();
	float GetSuccess_prc();

	// Same for Setters :
	void SetName(char name);
	void SetStudents(int students);
	void SetSuccess_prc(float successPrc);

	
	void ReadData();

	void PrintInfo();

	~College();
};