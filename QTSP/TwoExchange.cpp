#include <iostream>
#include "TwoExchange.h"
#include "Tour.h"

using namespace std;


// Input:	Two nodes i,j to swap in Tour curTour and 4-dimensional cost
//			matrix Q.
// Output:	The change in objective resulting from exchanging i and j.
int Delta(int i, int j, int**** Q)
{
	int val = 0;
	return val;
}

// Input:	A tour curTour.
// Output:	A 2-Opt tour using first improvement to decide moves.
void TwoExchangeFirst(Tour* curTour, int n, int**** Q)
{
	start:
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 2; i < n; j++)
		{
			if (Delta(i, j, Q) < 0)
			{
				curTour.TwoSwapMove(i, j, curTour);
				goto start;
			}
		}
	}
}

// Input:	A tour curTour.
// Output:	A 2-Opt tour using best improvement to decide moves.
void TwoExchangeBest(Tour* curTour, int n, int**** Q)
{
	int minDelta, tempDelta = 0;
	int curBestSwap[2]; // stores the two best nodes to exchange
	start:
	tempDelta = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 2; i < n; j++)
		{
			tempDelta = Delta(i, j, Q);
			if (tempDelta < minDelta)
			{				
				curBestSwap[0] = i;
				curBestSwap[1] = j;
				minDelta = tempDelta;
			}
		}
	}
	if (minDelta < 0)
	{
		TwoSwapMove(curBestSwap[0], curBestSwap[1], curTour);
		goto start;
	}
	else
	{
	}
}