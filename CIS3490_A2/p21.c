#include <stdio.h>
#include <stdbool.h>
#include "functions.h"

void insertionSort(double* x, double* y, int length) {
	double swap;

	for (int i = 1 ; i < length; i++) {
	 	int diff = x[i-1] - x[i];
		while ( i > 0 && diff > 0) {
	    	swap = x[i];
	    	x[i] = x[i-1];
	    	x[i-1] = swap;

	    	swap = y[i];
	    	y[i] = y[i-1];
	    	y[i-1] = swap;
    		i--;
	    }
  	}

}

void BruteForceConvexHull (double x[], double y[]) {
	int count = 30000;
	bool greater = false;
	bool lessthen = false;
	bool alreadycontainsi = false;
	bool alreadycontainsj = false;
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	int points = 0;
	double resultsx[100];
	double resultsy[100];

	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < count; ++j)
		{
			alreadycontainsi = false;
			alreadycontainsj = false;
			greater = false;
			lessthen = false;
			if (i != j) {
				a = y[j] - y[i];
				b = x[i] - x[j];
				c = x[i]*y[j] - y[i]*x[j];
			} else {
				continue;
			}
			for (int k = 0; k < count; ++k)
			{
				if (k!=i && k!=j) {
					int linepoint = a * x[k] + b * y[k];
					if (linepoint > c) {
						greater = true;
					} else {
						lessthen = true;
					}
				}
			}


			if (greater != lessthen) {
				for (int z = 0; z < points; ++z)
				{
					if (resultsx[z] == x[i] && y[i] == resultsy[z]) {
						alreadycontainsi = true;
					}
					if (resultsx[z] == x[j] && y[j] == resultsy[z]) {
						alreadycontainsj = true;
					}
				}
				if (!alreadycontainsi) {
					resultsx[points] = x[i];
					resultsy[points] = y[i];
					points++;
				}

				if (!alreadycontainsj) {
					resultsx[points] = x[j];
					resultsy[points] = y[j];
					points++;
				}
			}
		}
	}

	insertionSort(resultsx, resultsy, points);

	printf("Convex hull points %d\n", points);
	printf("Points: \n");
	for (int i = 0; i < points; ++i)
	{
		printf("%0.1f %0.1f\n", resultsx[i], resultsy[i]);
	}
}
