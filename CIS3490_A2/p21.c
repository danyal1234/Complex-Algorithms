#include <stdio.h>
#include <stdbool.h>
#include "functions.h"

int BruteForceConvexHull (int x[], int y[]) {
	int count = 5000;
	bool greater = false;
	bool lessthen = false;
	bool alreadycontainsi = false;
	bool alreadycontainsj = false;
	double slope = 0.0;
	double yintercept = 0.0;
	int points = 0;
	int resultsx[5000];
	int resultsy[5000];

	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < count; ++j)
		{
			alreadycontainsi = false;
			alreadycontainsj = false;
			if (i != j) {
				slope = (y[i]-y[j])*1.0/(x[i]-x[j]);
				yintercept = y[i] - slope * x[i];
			} else {
				continue;
			}
			greater = false;
			lessthen = false;
			for (int k = 0; k < count; ++k)
			{
				if (k!=i && k!=j) {
					int linepoint = slope * x[k] + yintercept;
					if (linepoint > y[k]) {
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

	printf("%d\n", points);

	return points;
}
