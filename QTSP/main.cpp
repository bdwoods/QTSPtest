#include <iostream>
#include "Tour.h"

using namespace std;

int main (int argc, char **argv)
{
	Tour newTour(5);
	
	newTour.PrintArray();
	newTour.Print();
	newTour.PrintBackwards();


	cout << "Complete.\n";
	cin.get();
	return 0;
}