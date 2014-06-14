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

	//newTour.Flip(1, 2, 0, 1);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			for(int k=0; k<n; k++)
			{
				for(int l=0; l<n; l++)
				{
					cout << "(" << i << "," << j << ") -- (" << k << "," << l << ")    ";
					newTour.Flip(i, j, k, l);
				}
			}
		}
		cin.get();
	}
	

	cout << "\nPress any key to terminate.\n";
	cin.get();
	return 0;
}