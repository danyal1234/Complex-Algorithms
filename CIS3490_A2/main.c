#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>
#include "functions.h"

int main () {

	// int distinctNumbers[50000];
	double x[30000];
	double y[30000];
	// int P1Counter = 0;
	int P2counter = 0;
	char numberStore[26];
	struct timeb start, end;
	double timeTaken;

	FILE* inFile = fopen("data_1.txt", "r");

	// while(fscanf(inFile,"%s", numberStore)>0) {
	//     distinctNumbers[P1Counter] = atoi(numberStore);
	//     P1Counter++;
	// }

	// ftime(&start);
	// int inversionsBrute = BruteForceInversion(distinctNumbers);
	// ftime(&end);
	// timeTaken = end.time-start.time + (end.millitm-start.millitm) * 0.001;
	// printf("Time taken: %f\n", timeTaken);

	// int inversionsDivideConquer = 0;
	// ftime(&start);
	// DivideConquerInversion(distinctNumbers, 50000, &inversionsDivideConquer);
	// ftime(&end);
	// timeTaken = end.time-start.time + (end.millitm-start.millitm) * 0.001;
	// printf("Time taken: %f\n", timeTaken);

	inFile = fopen("data_2.txt", "r");


	while(fscanf(inFile,"%s", numberStore)>0) {
	    x[P2counter] = atof(numberStore);
	    fscanf(inFile,"%s", numberStore);
	    y[P2counter] = atof(numberStore);
	    P2counter++;
	    if (P2counter == 10) {
	    	break;
	    }
	}

	// ftime(&start);
	// BruteForceConvexHull(x, y);
	// ftime(&end);
	// timeTaken = end.time-start.time + (end.millitm-start.millitm) * 0.001;
	// printf("Time taken: %0.3f\n", timeTaken);

	ftime(&start);
	QuickSortConvexHull(x, y);
	ftime(&end);
	timeTaken = end.time-start.time + (end.millitm-start.millitm) * 0.001;
	printf("Time taken: %0.3f\n", timeTaken);

	return 0;
}
