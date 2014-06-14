#include <iostream>
#include <stdexcept>
#include <string>
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
	return pArray[i << 1] >> 1; // Equivalently, pArray[i * 2] / 2;
}

// Input:	The ID of a node in the tour
// Output:	Returns the ID of the previous node in the tour
int Tour::Prev(int i) 
{
	return pArray[(i << 1) + 1] >> 1; // Equivalently, pArray[(i * 2) + 1] / 2;
}

bool Tour::Between(int a, int b, int c)
{
	return 0;
}

void Tour::Flip(int a, int b, int c, int d)
{	//**Remove in final version**.
	try {
		CheckValidFlip(a, b, c, d);
	}
	catch (const std::invalid_argument& e) {
		std::cout << e.what();
    }
	catch (...) {
		std::cout << "Error in input to Flip function.";
	}

	// Perform 2-exchange.

}

// Display the tour on screen
void Tour::Print()
{
	std::cout << "0 ";
	int loc = Next(0);
	while(loc != 0)
	{
		std::cout << loc << " ";
		loc = Next(loc);
	}
	std::cout << "\n";
}

// Display the tour on screen
void Tour::PrintBackwards()
{
	std::cout << "0 ";
	int loc = Prev(0);
	while(loc != 0)
	{
		std::cout << loc << " ";
		loc = Prev(loc);
	}
	std::cout << "\n";
}

// Display the satellite array on screen (should be made private later)
void Tour::PrintArray()
{
	for(int i = 0; i < size<<1; i++)
	{
		std::cout << pArray[i] << " ";
	}
	std::cout << "\n";
}

//----------------------------------------------------------------------------------------------
//----------------------------------- Helper Functions -----------------------------------------
//----------------------------------------------------------------------------------------------


// Check for proper input: (a,b) and (c,d) are forward edges in the tour
void Tour::CheckValidFlip(int a, int b, int c, int d)
{
	if (b != Next(a)) {
		throw std::invalid_argument("(" + std::to_string(static_cast<long long>(a)) 
			+ "," + std::to_string(static_cast<long long>(b)) 
			+ ") isn't an edge.  Cannot perform 2-exchange.\n");
	}
	else if (d != Next(c)) {
		throw std::invalid_argument("(" + std::to_string(static_cast<long long>(c)) 
			+ "," + std::to_string(static_cast<long long>(d)) 
			+ ") isn't an edge.  Cannot perform 2-exchange.\n");
	}
	else if ((b == c) | (a == c) | (b == d) | (a == d))
	{
		throw std::invalid_argument("Cannot perform 2-exchange move on (" 
			+ std::to_string(static_cast<long long>(a)) + ","
			+ std::to_string(static_cast<long long>(b)) + ") and ("
			+ std::to_string(static_cast<long long>(c)) + ","
			+ std::to_string(static_cast<long long>(d)) + ").\n");
	}
	

}