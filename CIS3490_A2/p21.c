// ****************************************************
// Danyal Mahmood                          0956989
// CIS 3490                                Assignment 2
// dmahmood@uoguelph.ca                    Feb 10, 2020
// ****************************************************

#include <stdio.h>
#include <stdbool.h>
#include "functions.h"


// Quicksort based solution using planes by making line segments as outlined in pg. 113 of textbook

// insertion sort an array in increasing order
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

void BruteForceConvexHull (double x[], double y[], int count) {
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

			// create line segment
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
					//determine if all points on one side of line
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
					// make sure not to add duplicate set of points
					if (resultsx[z] == x[i] && y[i] == resultsy[z]) {
						alreadycontainsi = true;
					}
					if (resultsx[z] == x[j] && y[j] == resultsy[z]) {
						alreadycontainsj = true;
					}
				}

				// add new found points belonging to convex hull
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

	// sort points by x co-ordinates using insertion sort
	insertionSort(resultsx, resultsy, points);

	// display convex hull
	printf("Convex hull points: %d\n", points);
	printf("Points: \n");
	for (int i = 0; i < points; ++i)
	{
		printf("%0.1f %0.1f\n", resultsx[i], resultsy[i]);
	}
}
