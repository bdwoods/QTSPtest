#pragma once

//Satellite list implementation for Tours.
class Tour
{
private:
	int *pArray;
public:
	int size;
	


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
};

