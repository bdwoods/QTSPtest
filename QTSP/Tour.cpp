#include "Tour.h"


Tour::Tour(void)
{
}

Tour::Tour(int sz)
{
	pArray = new int[sz * 2];
	for (int i = 0; i < sz * 2; i++)
	{
		pArray[i] = i;
	}
	size = sz;
}


Tour::~Tour(void)
{
	delete [] pArray;
}

int Tour::Next(int i)
{
	return pArray[i]>>1;
}

int Tour::Prev(int i)
{
	return pArray[i + 1]^1;
}

bool Between(int a, int b, int c)
{
	return 0;
}
void Flip(int a, int b, int c, int d)
{
	
}