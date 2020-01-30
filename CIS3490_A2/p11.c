#include <stdio.h>
#include "functions.h"

int BruteForceInversion (int a[]) {

	int inversions = 0;
	int count = 50000;

	for (int i = 0; i < count-1; ++i)
	{
		for (int j = i+1; i < count; ++i)
		{
			if (a[i] < a[j]) {
				inversions++;
			}
		}
	}

	return inversions;
}
