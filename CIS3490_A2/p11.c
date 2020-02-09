// ****************************************************
// Danyal Mahmood                          0956989
// CIS 3490                                Assignment 2
// dmahmood@uoguelph.ca                    Feb 10, 2020
// ****************************************************

#include <stdio.h>
#include "functions.h"

// Brute force code to count all inversions

void BruteForceInversion (int a[], int count) {

	int inversions = 0;

	// compare current points with points ahead in the arra
	for (int i = 0; i < count-1; ++i)
	{
		for (int j = i+1; j < count; ++j)
		{
			// if element greater than element further in array count inversion
			if (a[i] > a[j]) {
				inversions++;
			}
		}
	}

	printf("Number of inversions brute force: %d\n", inversions);
}
