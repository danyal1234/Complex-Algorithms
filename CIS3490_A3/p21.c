// ****************************************************
// Danyal Mahmood                          0956989
// CIS 3490                                Assignment 3
// dmahmood@uoguelph.ca                    Mar 09, 2020
// ****************************************************

#include <stdio.h>
#include <stdbool.h>
#include "functions.h"


void BruteForceStringMatch (char input[], char array[44100][80], int count, int inputLength) {
	int occurencesFound = 0;
	int index = 0;
	int tempi = 0;
	int tempj = 0;
	
	for (int i = 0; i < count; ++i) {
		for (int j = 0; j < 80; ++j) {
			if (array[i][j] == '\n') {
				break;
			}

			index = 0;
			tempi = i;
			tempj = j;
			while(array[tempi][tempj] && input[index] == array[tempi][tempj]) {
				tempj++;
				index++;

				if (index == inputLength) {
					occurencesFound++;
					break;
				}
			}
		}
	}

	printf("Occurences Found: %d\n", occurencesFound);
}
