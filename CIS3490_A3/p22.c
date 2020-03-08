// ****************************************************
// Danyal Mahmood                          0956989
// CIS 3490                                Assignment 3
// dmahmood@uoguelph.ca                    Mar 09, 2020
// ****************************************************

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "functions.h"

// Hoorspools method of string match from textbook pg. 259

void HorspoolStringMatch (char input[], char array[], int count, int inputLength) {
	// create table values
	char tableChar[50];
	int shiftValues[50];

	int tableIndex = 0;
	bool alreadyExists = false;
	int arrayIndex = inputLength-1;
	int inputIndex = 0;
	int tempArrayIndex = 0;
	int occurencesFound = 0;
	int shiftAmount = 0;
	int shiftCount = 0;

	// create shift table
	for (int i = 0; i < inputLength-1; ++i) {
		for (int j = 0; j < tableIndex; ++j) {
			if (input[i] == tableChar[j]) {
				shiftValues[j] = inputLength - i - 1;
				alreadyExists = true;
			}
		}

		if (!alreadyExists) {
			tableChar[tableIndex] = input[i];
			shiftValues[tableIndex] = inputLength - i - 1;
			tableIndex++;
		}

		alreadyExists = false;
	}

	// search for substrings
	while (arrayIndex <= count) {
		inputIndex = inputLength-1;
		shiftAmount = inputLength;
		tempArrayIndex = arrayIndex;

		// check string match from rightmost index first
		while(array[tempArrayIndex] == input[inputIndex]) {
			if (inputIndex == 0) {
				occurencesFound++;
				break;
			}
			inputIndex--;
			tempArrayIndex--;
		}

		// use shift table value and shift
		for (int j = 0; j < tableIndex; ++j) {
			if (tableChar[j] == array[arrayIndex]) {
				shiftAmount = shiftValues[j];
				break;
			}
		}

		// shift index correct
		arrayIndex += shiftAmount;
		shiftCount++;
	}

	printf("Occurences Found: %d\n", occurencesFound);
	printf("Shift count: %d\n", shiftCount);
}
