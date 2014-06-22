#include <iostream>
#include <string>

#include "Tour.h"

using namespace std;

int main (int argc, char **argv)
{
	int n = 5;
	Tour newTour(n);
	
	newTour.PrintArray();
	
	newTour.Print();
	
	newTour.PrintBackwards();

	newTour.Flip(0,1,2,3);
	newTour.PrintArray();
	newTour.Print();
	newTour.PrintBackwards();

	newTour.Flip(0,2,3,4);
	newTour.PrintArray();
	newTour.Print();
	newTour.PrintBackwards();
	cout << "\nPress any key to terminate...";
	cin.get();
	return 0;
}