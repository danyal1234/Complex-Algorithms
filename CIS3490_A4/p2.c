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

TreeNode* createTreeNode (char words[][52], double probabilities[], int leftindex, int rightindex) {
	if (leftindex - rightindex == 0) {
		TreeNode* toReturn = (TreeNode*)malloc(sizeof(TreeNode));
		strcpy(toReturn->key, words[leftindex]);
		toReturn->averageComparisons = probabilities[leftindex];
		return toReturn;
	}

	double maxProbability = 0;
	int maxProbabilityIndex;

	for (int i = leftindex; i <= rightindex; ++i) {
		if (probabilities[i] > maxProbability) {
			maxProbability = probabilities[i];
			maxProbabilityIndex = i;
		}
	}

	TreeNode* toReturn = (TreeNode*)malloc(sizeof(TreeNode));
	strcpy(toReturn->key, words[maxProbabilityIndex]);
	toReturn->averageComparisons = maxProbability;

	if (maxProbabilityIndex == leftindex) {
		toReturn->right = createTreeNode(words, probabilities, leftindex+1, rightindex);
	} else if (maxProbabilityIndex == rightindex) {
		toReturn->left = createTreeNode(words, probabilities, leftindex, rightindex-1);
	} else {
		toReturn->left = createTreeNode(words, probabilities, leftindex, maxProbabilityIndex-1);
		toReturn->right = createTreeNode(words, probabilities, maxProbabilityIndex+1, rightindex);
	}

	return toReturn;
}

void GreedyBSTSearch (char words[][52], double probabilities[], int totalUniqueWords, char* userInput) {
	double maxProbability = 0;
	int maxProbabilityIndex;

	for (int i = 0; i <= totalUniqueWords; ++i) {
		if (probabilities[i] > maxProbability) {
			maxProbability = probabilities[i];
			maxProbabilityIndex = i;
		}
	}

	TreeNode root;
	strcpy(root.key, words[maxProbabilityIndex]);
	root.averageComparisons = maxProbability;

	root.left = createTreeNode(words, probabilities, 1, maxProbabilityIndex-1);
	root.right = createTreeNode(words, probabilities, maxProbabilityIndex+1, totalUniqueWords);

	TreeNode* nodeIter = &root;

	while(1) {
		if (strcmp(nodeIter->key, userInput) == 0) {
			printf("Compared with %s (%0.4f), found.\n", nodeIter->key, nodeIter->averageComparisons);
			return;
		} else if (strcmp(userInput, nodeIter->key) > 0) {
			printf("Compared with %s (%0.4f), go right subtree.\n", nodeIter->key, nodeIter->averageComparisons);
			nodeIter = nodeIter->right;
			if (nodeIter == NULL) {
				printf("Not found.\n");
				return;
			}
		} else {
			printf("Compared with %s (%0.4f), go left subtree.\n", nodeIter->key, nodeIter->averageComparisons);
			nodeIter = nodeIter->left;
			if (nodeIter == NULL) {
				printf("Not found.\n");
				return;
			}
		}
	}
}
