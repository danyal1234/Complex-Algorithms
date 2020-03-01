// ****************************************************
// Danyal Mahmood                          0956989
// CIS 3490                                Assignment 3
// dmahmood@uoguelph.ca                    Mar 09, 2020
// ****************************************************

#include <stdio.h>
#include <stdbool.h>
#include "functions.h"


void BruteForceStringMatch (char input[], char array[], int count, int inputLength) {
	int occurencesFound = 0;
	int index = 0;
	int tempi = 0;
	
	for (int i = 0; i < count; ++i) {
		index = 0;
		tempi = i;
		while(input[index] == array[tempi]) {
			tempi++;
			index++;

			if (index == inputLength) {
				occurencesFound++;
				break;
			}
		}
	}

	printf("Occurences Found: %d\n", occurencesFound);
}
