// ****************************************************
// Danyal Mahmood                          0956989
// CIS 3490                                Assignment 2
// dmahmood@uoguelph.ca                    Feb 10, 2020
// ****************************************************

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "functions.h"

// Quicksort based solution quickhull as outlined by procedure in pg. 195 of textbook

void findHalfHulls(int maxleft, int maxright, double x[], double y[], double resultsx[], double resultsy[], int* points, bool upper, int size) {
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	bool greater = false;
	bool lessthen = false;
	int maxdistance = 0;
	bool pointfound = false;
	int index = 0;

	// make end to end line segment
	a = y[maxright] - y[maxleft];
	b = x[maxleft] - x[maxright];
	c = x[maxleft]*y[maxright] - y[maxleft]*x[maxright];

	for (int i = 0; i < size; ++i)
	{
		// dont compare line endpoints to themselves
		if (i==maxleft || i==maxright) {
			continue;
		}

		greater = false;
		lessthen = false;

		//determine distance between points using dot product
		double distance = fabs(a*x[i] + b*y[i] + c)/sqrt(a*a + b*b);

		if (distance >  maxdistance) {
			maxdistance = distance;

			// determine if point on side of desired upper/lower half
			double linepoint = a * x[i] + b * y[i];
			if (linepoint > c) {
				greater = true;
			} else if (linepoint < c) {
				lessthen = true;
			} else {
				continue;
			} 

			// if furthest away from line on right upper/lower half make point of interest
			if (greater && upper) {
				index = i;
				pointfound = true;
			} else if (lessthen && !upper) {
				index = i;
				pointfound = true;		
			}
		}

	}

	// append point if found
	if (pointfound) {
		for (int z = 0; z < *points; ++z)
		{
			// make sure not to add duplicate set of points
			if (resultsx[z] == x[index] && y[index] == resultsy[z]) {
				return;
			}
		}
		resultsx[*points] = x[index];
		resultsy[*points] = y[index];
		*points = *points + 1;
	} else {
		// no more points above line segment, kill recursion
		return;
	}

	// use new points to create to new line segments with middle new point, continue process
	findHalfHulls(maxleft, index, x, y, resultsx, resultsy, points, upper, size);
	findHalfHulls(index, maxright, x, y, resultsx, resultsy, points, upper, size);
}



void QuickSortConvexHull (double x[], double y[], int size) {
	double maxleft = x[0];
	double maxright = x[0];
	double resultsx[30];
	double resultsy[30];
	int leftindex = 0;
	int rightindex = 0;
	int points = 2;

	//find max and min x value points and add to hull
	for (int i = 1; i < size; ++i)
	{
		if (x[i] < maxleft) {
			maxleft = x[i];
			leftindex = i;
		} else if (x[i] > maxright) {
			maxright = x[i];
			rightindex = i;
		}
	}

	resultsx[0] = x[leftindex];
	resultsy[0] = y[leftindex];
	resultsx[1] = x[rightindex];
	resultsy[1] = y[rightindex];

	//recursively divide and conquer upper and lower hulls
	findHalfHulls(leftindex, rightindex, x, y, resultsx, resultsy, &points, true, size);
	findHalfHulls(leftindex, rightindex, x, y, resultsx, resultsy, &points, false, size);

	// sort points by x-coordinate
	insertionSort(resultsx, resultsy, points);

	//display convex hull points
	printf("Convex hull points: %d\n", points);
	printf("Points: \n");
	for (int i = 0; i < points; ++i)
	{
		printf("%0.1f %0.1f\n", resultsx[i], resultsy[i]);
	}
}
