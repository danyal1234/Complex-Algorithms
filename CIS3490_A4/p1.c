// ****************************************************
// Danyal Mahmood                          0956989
// CIS 3490                                Assignment 3
// dmahmood@uoguelph.ca                    Mar 09, 2020
// ****************************************************

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "functions.h"

int insertedCount = 1;

typedef struct treeNode TreeNode;
struct treeNode{
	char key[52];
	double averageComparisons;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* createTree (double mainTable[][600], int rootTable[][600], char words[][52], int leftindex, int rightindex) {
	if (rootTable[leftindex][rightindex] == 0) {
		return NULL;
	}

	TreeNode* toReturn = (TreeNode*)malloc(sizeof(TreeNode));
	strcpy(toReturn->key, words[rootTable[leftindex][rightindex]]);
	toReturn->averageComparisons = mainTable[leftindex][rightindex];

	insertedCount++;

	toReturn->left = createTree(mainTable, rootTable, words, leftindex, rootTable[leftindex][rightindex]-1);
	if (toReturn->left == NULL) {
		return toReturn;
	}
	toReturn->right = createTree(mainTable, rootTable, words, rootTable[leftindex][rightindex]+1, rightindex);

	return toReturn;
}

void OptimalBSTSearch (char words[][52], double probabilities[], int totalUniqueWords, char* userInput) {
	double mainTable[totalUniqueWords+1][totalUniqueWords];
	int rootTable[totalUniqueWords+1][totalUniqueWords];
	int j = 0;
	int kmin = 0;
	double minval = 0;
	bool minvalset = false;
	double sum = 0;

	for (int i = 1; i <= totalUniqueWords; ++i) {
		mainTable[i][i] = probabilities[i];
		rootTable[i][i] = i;
	}

	mainTable[totalUniqueWords+1][totalUniqueWords] = 0;

	for (int d = 1; d <= totalUniqueWords-1; ++d) {
		for (int i = 1; i <= totalUniqueWords-d; ++i) {
			j = i + d;
			minvalset = false;
			for (int k = i; k <= j; ++k) {
				if (mainTable[i][k-1]+mainTable[k+1][j] < minval || minvalset == false) {
					minvalset = true;
					minval = mainTable[i][k-1]+mainTable[k+1][j];
					kmin = k;
				}
			}
			rootTable[i][j] = kmin;
			sum = 0;
			for (int s = i; s <= j; ++s) {
				sum += probabilities[s];
			}

			mainTable[i][j] = minval + sum;
		}
	}

	TreeNode root;
	strcpy(root.key, words[rootTable[1][totalUniqueWords]]);
	root.averageComparisons = mainTable[1][totalUniqueWords];

	root.left = createTree(mainTable, rootTable, words, 1, rootTable[1][totalUniqueWords]-1);
	root.right = createTree(mainTable, rootTable, words, rootTable[1][totalUniqueWords]+1, totalUniqueWords);

	TreeNode* nodeIter = &root;

	while(1) {
		if (strcmp(nodeIter->key, userInput) == 0) {
			printf("Compared with %s (%0.2f), found.\n", nodeIter->key, nodeIter->averageComparisons);
			return;
		} else if (strcmp(userInput, nodeIter->key) > 0) {
			printf("Compared with %s (%0.2f), go right subtree.\n", nodeIter->key, nodeIter->averageComparisons);
			nodeIter = nodeIter->right;
			if (nodeIter == NULL) {
				printf("Not found.\n");
				return;
			}
		} else {
			printf("Compared with %s (%0.2f), go left subtree.\n", nodeIter->key, nodeIter->averageComparisons);
			nodeIter = nodeIter->left;
			if (nodeIter == NULL) {
				printf("Not found.\n");
				return;
			}
		}
	}

}
