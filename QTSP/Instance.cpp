#include <iostream>
#include "Instance.h"
#include <time.h>

Instance::Instance(void)
{
}

Instance::Instance(int sz)
{
	size = sz;
	srand(time(NULL));
	int**** Qmat;

	Qmat = new int***[size];
	for(int i = 0; i < size; i++) {
		Qmat[i] = new int**[size];
		for(int j = 0; j < size; j++) {
			Qmat[i][j] = new int*[size];
			for(int k = 0; k < size; k++) {
				Qmat[i][j][k] = new int[size];
				for(int l = 0; l < size; l++) {
					Qmat[i][j][k][l] = rand() % 100;
					//std::cout << Qmat[i][j][k][l] << " ";
				}
			}
		}
	}
	Q = Qmat;
	std::cout << "Successfully created instance on " << size << " nodes.\n";
}

Instance::~Instance(void)
{
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			for(int k = 0; k < size; k++) {
				delete [] Q[i][j][k];
			}
			delete [] Q[i][j];
		}
		delete [] Q[i];
	}
	delete [] Q;
	std::cout << "Successfully cleared Q from memory.\n";
}

void Instance::DisplayQ(void)
{
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			for(int k = 0; k < size; k++) {
				for(int l = 0; l < size; l++) {
					std::cout << Q[i][j][k][l] << " ";
				}
				std::cout << "\n";
			}
			std::cout << "\n";
		}
		std::cout << "\n";
	}

}
