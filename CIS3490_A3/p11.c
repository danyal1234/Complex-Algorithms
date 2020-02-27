// ****************************************************
// Danyal Mahmood                          0956989
// CIS 3490                                Assignment 3
// dmahmood@uoguelph.ca                    Mar 09, 2020
// ****************************************************

#include <stdio.h>
#include <stdbool.h>
#include "functions.h"

// Brute force code to count all anagrams

void BruteForceAnagrams (int a[], int count) {

	int count1[10] = {0,0,0,0,0,0,0,0,0,0};
	int count2[10] = {0,0,0,0,0,0,0,0,0,0};

	int index1 = 0;
	int index2 = 0;

	int anagrams[50000];
	int finishedCount = 0;
	bool found = false;

	char string1[26];
	char string2[26];

	// compare current points with points ahead in the arra
	for (int i = 0; i < count-1; ++i) {
		sprintf(string1, "%d", a[i]);


		while(string1[index1] != '\0') {
			switch (string1[index1]) {
				case '0':
					count1[0]++;
				case '1':
					count1[1]++;
				case '2':
					count1[2]++;
				case '3':
					count1[3]++;
				case '4':
					count1[4]++;
				case '5':
					count1[5]++;
				case '6':
					count1[6]++;
				case '7':
					count1[7]++;
				case '8':
					count1[8]++;
				case '9':
					count1[9]++;
			}

			index1++;
		}

		for (int j = i+1; j < count; ++j) {
			if (i != j) {
				sprintf(string2, "%d", a[j]);
			}

			while(string1[index2] != '\0') {
				switch (string1[index2]) {
					case '0':
						count1[0]++;
					case '1':
						count1[1]++;
					case '2':
						count1[2]++;
					case '3':
						count1[3]++;
					case '4':
						count1[4]++;
					case '5':
						count1[5]++;
					case '6':
						count1[6]++;
					case '7':
						count1[7]++;
					case '8':
						count1[8]++;
					case '9':
						count1[9]++;
				}

				index2++;
			}

			for (int i = 0; i < 10; ++i) {
				if (count1[i] == count2[i]) {
					if (i == 9) {
						for (int i = 0; i < finishedCount; ++i) {
							if (anagrams[finishedCount] == a[j]) {
								found = true;
							}
						}

						if (!found) {
							finishedCount++;
							printf("%d\n", finishedCount);
							anagrams[finishedCount] = a[j];
						}
					}
				} else {
					break;
				}
			}

			for (int i = 0; i < 10; ++i) {
				count2[i] = 0;
			}

			found = false;
		}

		for (int i = 0; i < 10; ++i) {
			count1[i] = 0;
		}

			found = false;
	}

	// printf("Number of inversions brute force: %d\n", inversions);
}
