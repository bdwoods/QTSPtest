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
	for (int i = 0; i < (sz - 1) * 2; i+=2) {
		pArray[i] = i + 2;
	}
	pArray[(sz - 1) * 2] = 0;
	pArray[1] = 2 * sz - 1;
	for (int i = 3; i < sz * 2; i+=2) {
		pArray[i] = i - 2;
	}
	size = sz;
}


Tour::~Tour(void)
{
	delete [] pArray;
}

/*
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
*/

// Input:	The index of a node in the tour
// Output:	Returns the index of the next node in the tour
int Tour::Next(int i) 
{
	return pArray[i];
}

/* Input:	The index of a node in the tour
   Output:	Returns the index of the previous node in the tour */
int Tour::Prev(int i) 
{
	return pArray[i^1];
}


bool Tour::Between(int a, int b, int c)
{
	return 0;
}

void Tour::Flip(int a, int b, int c, int d)
{	//**Remove check in final version**.
	try {
		//CheckValidFlip(a, b, c, d);
	}
	catch (const std::invalid_argument& e) {
		std::cout << e.what();
    }
	catch (...) {
		std::cout << "Error in input to Flip function.";
	}

	// Perform 2-exchange.

	// Get locations and sort out which index is the forward/reverse direction
	// at each node i, j, k, l.
	int loc_if, loc_ir, loc_jf, loc_jr, loc_kf, loc_kr, loc_lf, loc_lr;
	if (GetID(pArray[a<<1]) == b) {
		loc_if = a<<1;
		loc_ir = (a<<1) + 1;
	}
	else if (GetID(pArray[(a<<1) + 1]) == b) {
		loc_if = (a<<1) + 1;
		loc_ir = a<<1;
	}
	loc_jf = pArray[loc_if];
	loc_jr = pArray[loc_if]^1;
	if (GetID(pArray[c<<1]) == d) {
		loc_kf = c<<1;
		loc_kr = (c<<1) + 1;
	}
	else if (GetID(pArray[(c<<1) + 1]) == d) {
		loc_kf = (c<<1) + 1;
		loc_kr = c<<1;
	}
	loc_lf = pArray[loc_kf];
	loc_lr = pArray[loc_kf]^1;

	// Change pointers to make the 2-exchange move.
	pArray[loc_if] = loc_kr;
	pArray[loc_jr] = loc_lf;
	pArray[loc_kf] = loc_ir;
	pArray[loc_lr] = loc_jf;
}

// Display the tour on screen.
void Tour::Print()
{
	std::cout << "0 ";
	int loc = Next(0);
	while(GetID(loc) != 0) {
		std::cout << GetID(loc) << " ";
		loc = Next(loc);
	}
	std::cout << GetID(loc) << "\n";
}

// Display the tour on screen.
void Tour::PrintBackwards()
{
	std::cout << "0 ";
	int loc = Prev(0);
	while(GetID(loc) != 0) {
		std::cout << GetID(loc) << " ";
		loc = Next(loc);
	}
	std::cout << GetID(loc) << "\n";
}

// Display the satellite list on screen (should be made private later).
void Tour::PrintArray()
{
	for(int i = 0; i < size<<1; i++)
		std::cout << pArray[i] << " ";
	std::cout << "\n";
}

/*----------------------------------------------------------------------------------------------
------------------------------------- Helper Functions -----------------------------------------
----------------------------------------------------------------------------------------------*/

int Tour::GetID(int i)
{
	return i>>1;
}

// Check for proper input: (a,b) and (c,d) are forward edges in the tour
void Tour::CheckValidFlip(int a, int b, int c, int d)
{
	if (a < 0 || b < 0 || c < 0 || d < 0)
		throw std::invalid_argument("Negative index entered.  Cannot perform 2-exchange.\n");
	else if (b != GetID(Next(a)) && a != GetID(Next(b))) {
		throw std::invalid_argument("(" + std::to_string(static_cast<long long>(a)) 
			+ "," + std::to_string(static_cast<long long>(b)) 
			+ ") isn't an edge.  Cannot perform 2-exchange.\n");
	}
	else if (d != GetID(Next(c)) && c != GetID(Next(d))) {
		throw std::invalid_argument("(" + std::to_string(static_cast<long long>(c)) 
			+ "," + std::to_string(static_cast<long long>(d)) 
			+ ") isn't an edge.  Cannot perform 2-exchange.\n");
	}
	else if ((b == c) || (a == c) || (b == d) || (a == d))
	{
		throw std::invalid_argument("Cannot perform 2-exchange move on (" 
			+ std::to_string(static_cast<long long>(a)) + ","
			+ std::to_string(static_cast<long long>(b)) + ") and ("
			+ std::to_string(static_cast<long long>(c)) + ","
			+ std::to_string(static_cast<long long>(d)) + ").\n");
	}
}

bool Tour::ValidateTour()
{
	int* numbers;
	numbers = new int[size];
	return true;
}


