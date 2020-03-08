// ****************************************************
// Danyal Mahmood                          0956989
// CIS 3490                                Assignment 3
// dmahmood@uoguelph.ca                    Mar 09, 2020
// ****************************************************

#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>
#include "functions.h"

int main (int argc, char *argv[]) {

	if (argc != 3)
	{
		printf("Two files not specified. Exiting..\n");
		return -1;
	}

	int anagramNumbers[50000];
	int P1Counter = 0;
	int P2counter = 0;
	char numberStore[26];
	char lines[44100][80];
	char allLines[44100*80];
	int allCharCount = 0;
	struct timeb start, end;
	double timeTaken;
	char userInput[5];
	char option1Input[52];
	int inputLength = 0;

	printf("1) Brute Force Anagram Detection\n");
    printf("2) Presort Anagram Detection\n");
    printf("3) Brute Force String Search\n");
    printf("4) Horspool's String Search\n");
    printf("5) Boyer-Moore String Search\n");
    printf("Enter algorithm to run: ");

	scanf("%s", userInput);
	int menuChoice  = atoi(userInput);

	FILE* inFile = fopen(argv[1], "r");

	// parse integers
	while(fscanf(inFile,"%s", numberStore)>0) {
	    anagramNumbers[P1Counter] = atoi(numberStore);
	    P1Counter++;
	}

	if (menuChoice == 1) {
		printf("Enter anagram to look for: ");
		scanf("%s", option1Input);
		int p11choice = atoi(option1Input);
		ftime(&start);
		BruteForceAnagrams(anagramNumbers, P1Counter, p11choice);
		ftime(&end);
		timeTaken = end.time-start.time + (end.millitm-start.millitm) * 0.001;
		printf("Time taken: %0.4f\n", timeTaken);
	}

	if (menuChoice == 2) {
		printf("Enter anagram to look for: ");
		scanf("%s", option1Input);
		int p12choice = atoi(option1Input);
		ftime(&start);
		PreSortAnagrams(anagramNumbers, P1Counter, p12choice);
		ftime(&end);
		timeTaken = end.time-start.time + (end.millitm-start.millitm) * 0.001;
		printf("Time taken: %0.4f\n", timeTaken);
	}

	inFile = fopen(argv[2], "r");

	while(fgets(lines[P2counter], 80, inFile)) {
		P2counter++;
	}

	// parse lines of text
	for (int i = 0; i < P2counter; ++i) {
		for (int j = 0; j < 80; ++j) {
			allLines[allCharCount] = lines[i][j];
			allCharCount++;
			if (lines[i][j] == '\n') {
				break;
			}
		}
	}

	if (menuChoice == 3) {
		printf("Enter string to look for: ");
		scanf("%s", option1Input);
		int i = 0;
		while(option1Input[i] != '\0') {
			inputLength++;
			i++;
		}

		ftime(&start);
		BruteForceStringMatch(option1Input, allLines, allCharCount, inputLength);
		ftime(&end);
		timeTaken = end.time-start.time + (end.millitm-start.millitm) * 0.001;
		printf("Time taken: %0.4f\n", timeTaken);
	}

	if (menuChoice == 4) {
		printf("Enter string to look for: ");
		scanf("%s", option1Input);
		int i = 0;
		while(option1Input[i] != '\0') {
			inputLength++;
			i++;
		}

		ftime(&start);
		HorspoolStringMatch(option1Input, allLines, allCharCount, inputLength);
		ftime(&end);
		timeTaken = end.time-start.time + (end.millitm-start.millitm) * 0.001;
		printf("Time taken: %0.4f\n", timeTaken);
	}

	if (menuChoice == 5) {
		printf("Enter string to look for: ");
		scanf("%s", option1Input);
		int i = 0;
		while(option1Input[i] != '\0') {
			inputLength++;
			i++;
		}

		ftime(&start);
		BoyerMooreStringMatch(option1Input, allLines, allCharCount, inputLength);
		ftime(&end);
		timeTaken = end.time-start.time + (end.millitm-start.millitm) * 0.001;
		printf("Time taken: %0.4f\n", timeTaken);
	}

	fclose(inFile);

	return 0;
}
