// ****************************************************
// Danyal Mahmood                          0956989
// CIS 3490                                Assignment 4
// dmahmood@uoguelph.ca                    Mar 30, 2020
// ****************************************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "functions.h"

TreeNode* createTreeNode (char words[][52], double probabilities[], int size) {
	if (size == 1) {
		return NULL;
	}

	double maxProbability = 0;
	int maxProbabilityIndex;

	for (int i = 0; i < size; ++i) {
		if (probabilities[i] > maxProbability) {
			maxProbability = probabilities[i];
			maxProbabilityIndex = i;
		}
	}

	TreeNode* toReturn = (TreeNode*)malloc(sizeof(TreeNode));
	strcpy(toReturn->key, words[maxProbabilityIndex]);
	toReturn->averageComparisons = maxProbability;

	int half1 = maxProbabilityIndex;
	int half2 = size - maxProbabilityIndex;

	char firstHalf[half1][52];
	char secondHalf[half2][52];
	double firstHalfProb[half1];
	double secondHalfProb[half2];

	for (int i = 0; i < half1; ++i) {
		strcpy(firstHalf[i], words[i]); 
		firstHalfProb[i] = probabilities[i];
	}

	for (int i = half1+1; i < size; ++i) {
		strcpy(secondHalf[i-half1+1], words[i]);
		secondHalfProb[i] = probabilities[i];
	}

	toReturn->left = createTreeNode(firstHalf, firstHalfProb, half1);
	if (toReturn->left == NULL) {
		return toReturn;
	}
	toReturn->right = createTreeNode(secondHalf, secondHalfProb, half2);

	return toReturn;
}

void GreedyBSTSearch (char words[][52], double probabilities[], int totalUniqueWords, char* userInput) {
	double maxProbability = 0;
	int maxProbabilityIndex;

	for (int i = 0; i < totalUniqueWords; ++i) {
		if (probabilities[i] > maxProbability) {
			maxProbability = probabilities[i];
			maxProbabilityIndex = i;
		}
	}

	int half1 = maxProbabilityIndex;
	int half2 = totalUniqueWords - maxProbabilityIndex;

	char firstHalf[half1][52];
	char secondHalf[half2][52];
	double firstHalfProb[half1];
	double secondHalfProb[half2];

	for (int i = 0; i < half1; ++i) {
		strcpy(firstHalf[i], words[i]); 
		firstHalfProb[i] = probabilities[i];
	}

	for (int i = half1+1; i < totalUniqueWords; ++i) {
		strcpy(secondHalf[i-half1+1], words[i]);
		secondHalfProb[i] = probabilities[i];
	}

	TreeNode root;
	strcpy(root.key, words[maxProbabilityIndex]);
	root.averageComparisons = maxProbability;

	printf("%s %0.3f\n", root.key, root.averageComparisons);

	root.left = createTreeNode(firstHalf, firstHalfProb, half1);
	root.right = createTreeNode(secondHalf, secondHalfProb, half2);

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
