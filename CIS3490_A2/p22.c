#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "functions.h"

void findHalfHulls(int maxleft, int maxright, double x[], double y[], double resultsx[], double resultsy[], int* points, bool upper) {
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	bool greater = false;
	bool lessthen = false;
	int maxdistance = 0;
	bool pointfound = false;
	int index = 0;

	a = y[maxleft] - y[maxright];
	b = x[maxright] - x[maxleft];
	c = x[maxright]*y[maxleft] - y[maxright]*x[maxleft];

	for (int i = 0; i < 10; ++i)
	{
		if (i==maxleft || i==maxright) {
			continue;
		}
		greater = false;
		lessthen = false;
		int distance = fabs((a*x[i] + b*y[i] + c) / (sqrt(b*b + a*a)));
		int linepoint = a * x[i] + b * y[i];
		if (linepoint > c) {
			greater = true;
		} else {
			lessthen = true;
		}
		if (greater && upper) {
			if (distance >  maxdistance) {
				maxdistance = distance;
				index = i;
				pointfound = true;
			}
		} else if (lessthen && !upper) {
			if (distance >  maxdistance) {
				maxdistance = distance;
				index = i;
				pointfound = true;
			}
		}
	}

	if (pointfound) {
		resultsx[*points] = x[index];
		resultsy[*points] = y[index];
		*points = *points + 1;
	} else {
		return;
	}


	findHalfHulls(maxleft, index, x, y, resultsx, resultsy, points, upper);
	findHalfHulls(index, maxright, x, y, resultsx, resultsy, points, upper);
}



void QuickSortConvexHull (double x[], double y[]) {
	double maxleft = x[0];
	double maxright = x[0];
	double resultsx[100];
	double resultsy[100];
	int leftindex = 0;
	int rightindex = 0;

	int points = 2;

	for (int i = 1; i < 10; ++i)
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

	findHalfHulls(leftindex, rightindex, x, y, resultsx, resultsy, &points, true);
	findHalfHulls(leftindex, rightindex, x, y, resultsx, resultsy, &points, false);

	// insertionSort(resultsx, resultsy, points);

	printf("Convex hull points %d\n", points);
	printf("Points: \n");
	for (int i = 0; i < points; ++i)
	{
		printf("%0.1f %0.1f\n", resultsx[i], resultsy[i]);
	}
}
