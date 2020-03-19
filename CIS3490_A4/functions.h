#include <stdio.h>

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
