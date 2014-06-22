#pragma once

//Satellite list implementation for Tours.
class Tour
{
private:
	int *pArray;
	void CheckValidFlip(int a, int b, int c, int d);

public:
	int size;
	int GetID(int i);

	// Default Constructor
	Tour(void);
	// Constructor with number of nodes entered as size
	Tour(int size);
	// Destructor
	~Tour(void);

	int Next(int i);
	int Prev(int i);
	bool Between(int a, int b, int c);
	void Flip(int a, int b, int c, int d);

	void Print();
	void PrintBackwards();

	void PrintArray();
};

