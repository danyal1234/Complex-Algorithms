// ****************************************************
// Danyal Mahmood                          0956989
// CIS 3490                                Assignment 3
// dmahmood@uoguelph.ca                    Mar 09, 2020
// ****************************************************

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "functions.h"

// String search using bad match and good suffic tables as pg. 263 of textbook

void BoyerMooreStringMatch (char input[], char array[], int count, int inputLength) {
	// create bad match table values
	char badTableChar[50];
	int badShiftValues[50];

	// create good match table
	int goodTableMatch[30] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

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
		for (int j = 0; j < badTableIndex; ++j) {
			if (input[i] == badTableChar[j]) {
				badShiftValues[j] = inputLength - i - 1;
				alreadyExists = true;
			}
		}

		if (!alreadyExists) {
			badTableChar[badTableIndex] = input[i];
			badShiftValues[badTableIndex] = inputLength - i - 1;
			badTableIndex++;
		}

		alreadyExists = false;
	}

	// create good match table
	int matchedLength = 1;
	int checkCounter = 0;
	int substringCount = 0;
	bool suffixFound = false;
	int tempShift = 0;
	int foundCount = 0;

	// compute good suffix table based on matched Length
	while(matchedLength != inputLength){
		suffixFound = false;

		while(1) {
			// find first character of substring
			if (input[inputLength-1] == input[inputLength-2-checkCounter]) {
				foundCount++;
				substringCount = checkCounter;
				if (matchedLength == foundCount) {
					tempShift = checkCounter + 1;
					suffixFound = true;
				}

				// verify substring 
				while(foundCount != matchedLength) {
					substringCount--;
					if (input[inputLength-1-substringCount] == input[inputLength-2-substringCount]) {
						foundCount++;
						//if prefix found, indicate shift amount based on matched
						if (matchedLength == foundCount) {
							suffixFound = true;
							tempShift = checkCounter+1;
							break;
						}
					} else {
						break;
					}
				}
			}

			if (inputLength-2-checkCounter == 0 || suffixFound) {
				// if prefix not found shift entire legth of string
				if (tempShift == 0) {
					tempShift = inputLength;
				}
				break;
			}

			checkCounter++;
		}

		goodTableMatch[matchedLength] = tempShift;
		matchedLength++;
		checkCounter = 0;
		foundCount = 0;
	}

	// search for string
	while (arrayIndex <= count) {
		inputIndex = inputLength-1;
		shiftAmount = inputLength;
		tempArrayIndex = arrayIndex;

		// compare input and index
		while(array[tempArrayIndex] == input[inputIndex]) {
			if (inputIndex == 0) {
				occurencesFound++;
				break;
			}
			matchCount++;
			inputIndex--;
			tempArrayIndex--;
		}

		// find shift amount based on bad match table
		for (int j = 0; j < badTableIndex; ++j) {
			if (badTableChar[j] == array[tempArrayIndex]) {
				// determine shift amount based on Boyer-Moore
				shiftAmount = badShiftValues[j] - matchCount;
				if (shiftAmount<=0) {
					shiftAmount = 1;
				}
				break;
			}
		}

		// take max of good match and bad table
		if (shiftAmount < goodTableMatch[matchCount]) {
			shiftAmount = goodTableMatch[matchCount];
		}

		arrayIndex += shiftAmount;
		matchCount = 0;
	}

	printf("Occurences Found: %d\n", occurencesFound);
}
