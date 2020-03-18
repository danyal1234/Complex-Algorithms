// ****************************************************
// Danyal Mahmood                          0956989
// CIS 3490                                Assignment 3
// dmahmood@uoguelph.ca                    Mar 09, 2020
// ****************************************************

#include <stdio.h>
#include <stdbool.h>
#include "functions.h"

void OptimalBSTSearch (char words[][52], double probabilities[], int totalUniqueWords) {
	double mainTable[totalUniqueWords+1][totalUniqueWords];
	int rootTable[totalUniqueWords+1][totalUniqueWords];
	int j = 0;
	int kmin = 0;
	double minval = 0;
	double sum = 0;

	for (int i = 1; i <= totalUniqueWords; ++i) {
		mainTable[i][i-1] = 0;
		mainTable[i][i] = probabilities[i];
		rootTable[i][i] = i;
	}

	mainTable[totalUniqueWords+1][totalUniqueWords] = 0;

	for (int d = 1; d <= totalUniqueWords-1; ++d) {
		for (int i = 1; i <= totalUniqueWords-d; ++i) {
			j = i + d;
			minval = 2000000000;
			for (int k = i; k <= j; ++k) {
				if (mainTable[i][k-1]+mainTable[k+1][j] < minval) {
					minval = mainTable[i][k-1]+mainTable[k+1][j];
					kmin = k;
				}
			}
			rootTable[i][j] = kmin;
			sum = probabilities[i];
			for (int s = i+1; s <= j; ++s) {
				sum += probabilities[s];
			}

			mainTable[i][j] = minval + sum;
		}
	}

}
