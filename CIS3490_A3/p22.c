// ****************************************************
// Danyal Mahmood                          0956989
// CIS 3490                                Assignment 3
// dmahmood@uoguelph.ca                    Mar 09, 2020
// ****************************************************

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "functions.h"

void HorspoolStringMatch (char input[], char array[44100][80], int count, int inputLength) {
	// create table values
	char tableChar[50];
	int shiftValues[50];
	int tableIndex;
	bool alreadyExists = false;

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
			tableChar[tableIndex] = input[i];
			shiftValues[tableIndex] = inputLength - i - 1;
			tableIndex++;
		}

		alreadyExists = false;
	}

	for (int i = inputLength-1; i < count; ++i) {
		
	}
}
