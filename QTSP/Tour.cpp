#include <iostream>
#include "Tour.h"

using namespace std;

Tour::Tour(void)
{
}

//Default construct and fill array with the tour 0,1,2,3,...n,0
Tour::Tour(int sz)
{
	pArray = new int[sz * 2];
	for (int i = 0; i < (sz - 1) * 2; i+=2)
	{
		pArray[i] = i + 2;
	}
	pArray[(sz - 1) * 2] = 0;
	pArray[1] = 2 * sz - 1;
	for (int i = 3; i < sz * 2; i+=2)
	{
		pArray[i] = i - 2;
	}
	size = sz;
}


Tour::~Tour(void)
{
	delete [] pArray;
}

// Input:	The ID of a node in the tour
// Output:	Returns the ID of the next node in the tour
int Tour::Next(int i)
{
	return pArray[i * 2]>>1;
}

// Input:	The ID of a node in the tour
// Output:	Returns the ID of the previous node in the tour
int Tour::Prev(int i)
{
	return pArray[i * 2 + 1]>>1;
}

bool Tour::Between(int a, int b, int c)
{
	return 0;
}
void Tour::Flip(int a, int b, int c, int d)
{
	
}

// Display the tour
void Tour::Print()
{
	cout << "0 ";
	int loc = Next(0);
	while(loc != 0)
	{
		cout << loc << " ";
		loc = Next(loc);
	}
	cout << "\n";
}

// Display the tour
void Tour::PrintBackwards()
{
	cout << "0 ";
	int loc = Prev(0);
	while(loc != 0)
	{
		cout << loc << " ";
		loc = Prev(loc);
	}
	cout << "\n";
}

// Display the satellite array (should be made private later)
void Tour::PrintArray()
{
	for(int i = 0; i < 2 * size; i++)
	{
		cout << pArray[i] << " ";
	}
	cout << "\n";
}