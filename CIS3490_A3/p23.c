// ****************************************************
// Danyal Mahmood                          0956989
// CIS 3490                                Assignment 3
// dmahmood@uoguelph.ca                    Mar 09, 2020
// ****************************************************

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "functions.h"

void BoyerMooreStringMatch (char input[], char array[], int count, int inputLength) {
	// create bad match table values
	char badTableChar[50];
	int badShiftValues[50];

	// create good match table
	int goodTableMatch[50];
	int goodShiftValues[50];

	int badTableIndex = 0;
	bool alreadyExists = false;
	int arrayIndex = inputLength-1;
	int inputIndex = 0;
	int tempArrayIndex = 0;
	int occurencesFound = 0;
	int shiftAmount = 0;
	int matchCount = 0;

	// create bad matchtable
	for (int i = 0; i < inputLength-1; ++i) {
		for (int j = 0; j < 50; ++j) {
			if (!tableChar[j]) {
				break;
			}

			if (input[i] == tableChar[j]) {
				shiftValues[i] = inputLength - i - 1;
				alreadyExists = true;
			}
		}

		if (!alreadyExists) {
			tableChar[badTableIndex] = input[i];
			shiftValues[badTableIndex] = inputLength - i - 1;
			badTableIndex++;
		}

		alreadyExists = false;
	}

	for (int i = 0; i < inputLength; ++i) {
		while(){

		}
	}

	while (arrayIndex <= count) {
		inputIndex = inputLength-1;
		shiftAmount = inputLength;
		tempArrayIndex = arrayIndex;

		while(array[tempArrayIndex] == input[inputIndex]) {
			if (inputIndex == 0) {
				occurencesFound++;
				break;
			}
			matchCount++;
			inputIndex--;
			tempArrayIndex--;
		}

		for (int j = 0; j < badTableIndex; ++j) {
			if (tableChar[j] == array[tempArrayIndex]) {
				shiftAmount = shiftValues[j] - matchCount;
				if (shiftAmount<=0) {
					shiftAmount = 1;
				}
				break;
			}
		}

		arrayIndex += shiftAmount;
	}

	printf("Occurences Found: %d\n", occurencesFound);
}