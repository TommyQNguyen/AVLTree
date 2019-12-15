#pragma once

struct Node
{
	int value;
	int height = 0;
	Node* left = nullptr;
	Node* right = nullptr;
};

void showTree(Node* root, int maxDepth);
void showEmptyTreeMessage();
void resizeScreen(int maxWidth, int maxDepth);
int getDisplayedRowByDepth(int maxDepth, int currentDepth);
void printNode(Node* node, int x, int y, int maxDepth, int nodeDepth = 0);
void printLeftLink(int& x, int& y, int stopAt);
void printRightLink(int& x, int& y, int stopAt);
