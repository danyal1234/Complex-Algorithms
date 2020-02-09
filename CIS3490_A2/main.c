// ****************************************************
// Danyal Mahmood                          0956989
// CIS 3490                                Assignment 2
// dmahmood@uoguelph.ca                    Feb 10, 2020
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

	int distinctNumbers[50000];
	double x[30000];
	double y[30000];
	int P1Counter = 0;
	int P2counter = 0;
	char numberStore[26];
	struct timeb start, end;
	double timeTaken;
	char userInput[5];

	printf("1) Brute Force Inversion Problem\n");
    printf("2) Divide and Conquer Inversion Problem\n");
    printf("3) Brute Force Convex Hull Problem\n");
    printf("4) Divide and Conquer Convex Hull Problem\n");
    printf("Enter algorithm to run:");

	scanf("%s", userInput);
	int menuChoice  = atoi(userInput);

	FILE* inFile = fopen(argv[1], "r");

	while(fscanf(inFile,"%s", numberStore)>0) {
	    distinctNumbers[P1Counter] = atoi(numberStore);
	    P1Counter++;
	}
	if (menuChoice == 1) {
		ftime(&start);
		BruteForceInversion(distinctNumbers, P1Counter);
		ftime(&end);
		timeTaken = end.time-start.time + (end.millitm-start.millitm) * 0.001;
		printf("Time taken: %0.4f\n", timeTaken);
	}

	if (menuChoice == 2) {
		int inversionsDivideConquer = 0;
		ftime(&start);
		DivideConquerInversion(distinctNumbers, P1Counter, &inversionsDivideConquer);
		printf("Number of inversions divide and conquer force: %d\n", inversionsDivideConquer);
		ftime(&end);
		timeTaken = end.time-start.time + (end.millitm-start.millitm) * 0.001;
		printf("Time taken: %0.4f\n", timeTaken);
	}

	inFile = fopen(argv[2], "r");


	while(fscanf(inFile,"%s", numberStore)>0) {
	    x[P2counter] = atof(numberStore);
	    fscanf(inFile,"%s", numberStore);
	    y[P2counter] = atof(numberStore);
	    P2counter++;
	}

	if (menuChoice == 3)
	{
		ftime(&start);
		BruteForceConvexHull(x, y, P2counter);
		ftime(&end);
		timeTaken = end.time-start.time + (end.millitm-start.millitm) * 0.001;
		printf("Time taken: %0.4f\n", timeTaken);
	}

	if (menuChoice == 4)
	{
		ftime(&start);
		QuickSortConvexHull(x, y, P2counter);
		ftime(&end);
		timeTaken = end.time-start.time + (end.millitm-start.millitm) * 0.001;
		printf("Time taken: %0.4f\n", timeTaken);
	}

	fclose(inFile);

	return 0;
}
