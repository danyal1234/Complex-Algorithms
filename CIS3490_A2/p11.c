#include <stdio.h>
#include "functions.h"

void BruteForceInversion (int a[]) {

	int inversions = 0;
	int count = 50000;

	for (int i = 0; i < count-1; ++i)
	{
		for (int j = i+1; j < count; ++j)
		{
			if (a[i] > a[j]) {
				inversions++;
			}
		}
	}

	printf("Number of inversions brute force: %d\n", inversions);
}
