// ****************************************************
// Danyal Mahmood                          0956989
// CIS 3490                                Assignment 4
// dmahmood@uoguelph.ca                    Mar 30, 2020
// ****************************************************

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "functions.h"

int main (int argc, char *argv[]) {

	if (argc != 2) {
		printf("File not specified. Exiting..\n");
		return -1;
	}

	char words[2045][52];
	int wordFrequency[2045];
	char temp[52];
	double wordProbability[2045];
	int P1Counter = 1;
	char userInput[5];
	char option1Input[52];
	int totalWords = 0;
	bool wordFound = false;

	printf("1) Optimal BST search dynamic programming\n");
    printf("2) Optimal BST search greedy technique\n");
    printf("Enter algorithm to run: ");

	scanf("%s", userInput);
	int menuChoice  = atoi(userInput);

	FILE* inFile = fopen(argv[1], "r");

	// parse integers
	while(fscanf(inFile,"%s", words[P1Counter])>0) {
		totalWords++;
		for (int i = 0; i < P1Counter; ++i) {
			if (strcmp(words[i], words[P1Counter]) == 0) {
				wordFrequency[i] = wordFrequency[i] + 1;
				wordFound = true;
				break;
			}
		}

		if (wordFound) {
			wordFound = false;
			continue;
		}

		wordFrequency[P1Counter] =  1;
	    P1Counter++;
	}

	for (int i = 1; i < P1Counter; ++i) {
		wordProbability[i] = (double)wordFrequency[i] / (double)totalWords;
	}

	// bubble sort array alphabetically
	for (int i = 0; i < P1Counter; i++) {
      for (int j = i+1; j < P1Counter; j++)
         if (strcmp(words[i], words[j]) > 0) {
            strcpy(temp, words[i]); 
            strcpy(words[i], words[j]);
            strcpy(words[j], temp);

            double tempProb = wordProbability[i];
            wordProbability[i] = wordProbability[j];
            wordProbability[j] = tempProb;
         }
     }

	if (menuChoice == 1) {
		printf("Enter a key: ");
		scanf("%s", option1Input);
		OptimalBSTSearch(words, wordProbability, P1Counter-1, option1Input);
	}

	if (menuChoice == 2) {
		printf("Enter a key: ");
		scanf("%s", option1Input);
		GreedyBSTSearch(words, wordProbability, P1Counter-1, option1Input);
	}

	fclose(inFile);

	return 0;
}
