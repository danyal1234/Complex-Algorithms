// ****************************************************
// Danyal Mahmood                          0956989
// CIS 3490                                Assignment 4
// dmahmood@uoguelph.ca                    Mar 30, 2020
// ****************************************************

#include <stdio.h>

// used to create tree nodes for both problems
typedef struct treeNode TreeNode;
struct treeNode{
	char key[52];
	double averageComparisons;
	TreeNode* left;
	TreeNode* right;
};

// solution for p.1
void OptimalBSTSearch (char words[][52], double probabilities[], int totalUniqueWords, char* userInput);
// solution for p.2
void GreedyBSTSearch (char words[][52], double probabilities[], int totalUniqueWords, char* userInput);
