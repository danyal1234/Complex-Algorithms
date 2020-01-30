#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/timeb.h>
#include <math.h>
#include "functions.h"

int main () {

	int distinctNumbers[50000];
	int P1Counter = 0;

	FILE* inFile = fopen("data_1.txt", "r");

	char numberStore[26];
	while(fscanf(inFile,"%s", numberStore)>0) {
	    distinctNumbers[P1Counter] = atoi(numberStore);
	    P1Counter++;
	}

	int inversionsBrute = BruteForceInversion(distinctNumbers);
	printf("%d\n", inversionsBrute);

	// int inversionsDivideConquer = DivideConquer(distinctNumbers);


	return 0;
}
