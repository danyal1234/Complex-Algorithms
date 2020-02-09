#include <stdio.h>
#include "functions.h"

// Built using mergesort pseudocode from lecture 5: divide and conquer

void CountInversionsMerge(int b[], int c[], int a[], int p, int q, int *invCount) {
	// merge algorithm
	int i = 0;
	int j = 0;
	int k = 0;

	while(i<p && j<q) {
		// compare array containing earlier elements in array to latter
		if (b[i] < c[j]) {
			// add element and increase earlier array index
			a[k] = b[i];
			i++;
		} else {
			// every remaining item in b array must be inversion with c[j], add number of items left to compare to inversion count
			*invCount += p-i;
			// ass lement and increase later array index
			a[k] = c[j];
			j++;
		}

		k++;
	}

	if (i==p) {
		// append remainder of latter array if earlier array finish
		for (int x = j; x < q; ++x)
		{
			a[k] = c[x];
			k++;
		}
	} else {
		// append remainder of earlier array if latter array finish
		for (int x = i; x < p; ++x)
		{
			a[k] = b[x];
			k++;
		}
	}
}

void DivideConquerInversion (int a[], int size, int *invCount) {
	//mergesort algorithem
	if (size > 1) {

		// determine half size of array
		int half1 = size / 2;
		int half2 = size / 2;

		if (size%2 == 1) {
			half1 += 1;
		}

		//split arrays in half
		int firstHalf[half1];
		int secondHalf[half2];

		for (int i = 0; i < half1; ++i)
		{
			firstHalf[i] = a[i]; 
		}

		for (int i = half1; i < size; ++i)
		{
			secondHalf[i-half1] = a[i];
		}

		//split arrays further
		DivideConquerInversion(firstHalf, half1, invCount);
		DivideConquerInversion(secondHalf, half2, invCount);

		// assess half arrays and sort in increasing order
		CountInversionsMerge(firstHalf, secondHalf, a, half1, half2, invCount);
	}
}
