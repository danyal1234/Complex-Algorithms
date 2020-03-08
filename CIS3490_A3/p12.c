// ****************************************************
// Danyal Mahmood                          0956989
// CIS 3490                                Assignment 3
// dmahmood@uoguelph.ca                    Mar 09, 2020
// ****************************************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "functions.h"

// Built using mergesort pseudocode from Lecture 5: divide and conquer

void Merge(int b[], int c[], int a[], int p, int q) {
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
			// add element and increase later array index
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

void MergeSort (int a[], int size) {
	//mergesort algorithm
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
		MergeSort(firstHalf, half1);
		MergeSort(secondHalf, half2);

		// assess half arrays and sort in increasing order
		Merge(firstHalf, secondHalf, a, half1, half2);
	}
}

// find anagrams by using presorting method

void PreSortAnagrams (int a[], int count, int input) {
	int anagrams[50000];
	int finishedCount = 0;

	char string1[26];
	char string2[26];
	int intCounter = 0;
	char sortedNumber[52];
	int splitArray[52];
	char inputSorted[52];

	// convert integers into single digit array to sort 
	sprintf(string1, "%d", input);
	while(string1[intCounter] != '\0') {
		splitArray[intCounter] = string1[intCounter] - '0';
		intCounter++;
	}

	// sort array and converted back into single int
	MergeSort(splitArray, intCounter);
	for (int i = 0; i < intCounter; ++i) {
		inputSorted[i] = splitArray[i] + '0';
	}
	inputSorted[intCounter] = '\0';
	intCounter = 0;

	// find anagrams based on presorted method
	for (int i = 0; i < count; ++i)
	{
		sprintf(string2, "%d", a[i]);
		while(string2[intCounter] != '\0') {
			splitArray[intCounter] = string2[intCounter] - '0';
			intCounter++;
		}
		MergeSort(splitArray, intCounter);
		for (int i = 0; i < intCounter; ++i) {
			sortedNumber[i] = splitArray[i] + '0';
		}
		sortedNumber[intCounter] = '\0';
		if (strcmp(sortedNumber,inputSorted) == 0) {
			anagrams[finishedCount] = a[i];
			finishedCount++;
		}
		intCounter = 0;
	}

	// display anagrams
	printf("Anagrams:\n");
	for (int i = 0; i < finishedCount; ++i) {
		if (anagrams[i] == input) {
			finishedCount--;
		}
		printf("%d\n", anagrams[i]);
	}
	printf("Number of anagrams: %d\n", finishedCount);
}

