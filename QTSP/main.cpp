#include <iostream>
#include <string>


#include "Tour.h"
#include "Instance.h"

using namespace std;


int main (int argc, char **argv)
{
	int n = 5;
	Tour tour(n);

	Instance* inst;
	inst = new Instance(5);

	(*inst).DisplayQ();
	delete inst;

	

	cout << "\nPress any key to terminate...";
	cin.get();
	return 0;
}
