// ****************************************************
// Danyal Mahmood                          0956989
// CIS 3490                                Assignment 3
// dmahmood@uoguelph.ca                    Mar 09, 2020
// ****************************************************

#include <stdio.h>
#include <stdbool.h>
#include "functions.h"

// Brute force code to count all anagrams

void BruteForceAnagrams (int a[], int count, int input) {

	int count1[10] = {0,0,0,0,0,0,0,0,0,0};
	int count2[10] = {0,0,0,0,0,0,0,0,0,0};

	int index1 = 0;
	int index2 = 0;

	int anagrams[50000];
	int finishedCount = 0;
	bool found = false;
	bool equalVal = false;

	char string1[26];
	char string2[26];

	sprintf(string1, "%d", input);

	//make count of characters of input
	while(string1[index1] != '\0') {
		switch (string1[index1]) {
			case '0':
				count1[0] = count1[0] + 1;
				break;	
			case '1':
				count1[1] = count1[1] + 1;
				break;
			case '2':
				count1[2] = count1[2] + 1;
				break;
			case '3':
				count1[3] = count1[3] + 1;
				break;
			case '4':
				count1[4] = count1[4] + 1;
				break;
			case '5':
				count1[5] = count1[5] + 1;
				break;
			case '6':
				count1[6] = count1[6] + 1;
				break;
			case '7':
				count1[7] = count1[7] + 1;
				break;
			case '8':
				count1[8] = count1[8] + 1;
				break;
			case '9':
				count1[9] = count1[9] + 1;
				break;
		}

		index1++;
	}


	for (int j = 0; j < count; ++j) {
		sprintf(string2, "%d", a[j]);

		// count characters
		while(string2[index2] != '\0') {
			switch (string2[index2]) {
				case '0':
					count2[0] = count2[0] + 1;
					break;
				case '1':
					count2[1] = count2[1] + 1;
					break;
				case '2':
					count2[2] = count2[2] + 1;
					break;
				case '3':
					count2[3] = count2[3] + 1;
					break;
				case '4':
					count2[4] = count2[4] + 1;
					break;
				case '5':
					count2[5] = count2[5] + 1;
					break;
				case '6':
					count2[6] = count2[6] + 1;
					break;
				case '7':
					count2[7] = count2[7] + 1;
					break;
				case '8':
					count2[8] = count2[8] + 1;
					break;
				case '9':
					count2[9] = count2[9] + 1;
					break;
			}

			index2++;
		}

		index2 = 0;

		// check to see if amount of characters are equal
		for (int k = 0; k < 10; ++k) {
			if (count1[k] == count2[k]) {
				equalVal = true;
			} else {
				equalVal = false;
				break;
			}
		}

		// check to see valid anagrams and store
		if (equalVal) {
			for (int x = 0; x < finishedCount; ++x) {
				if (anagrams[x] == a[j] ||  anagrams[x] == input) {
					found = true;
					break;
				}
			}

			if (!found) {
				anagrams[finishedCount] = a[j];
				finishedCount++;
			}
		}

		// Clear count array
		for (int index = 0; index < 10; ++index) {
			count2[index] = 0;
		}

		found = false;
	}

	printf("Anagrams:\n");
	for (int i = 0; i < finishedCount; ++i) {
		printf("%d\n", anagrams[i]);
	}

	printf("Number of anagrams: %d\n", finishedCount);
}
