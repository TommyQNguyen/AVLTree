#include "tree.h"
#include <iostream>
#include <conio.h>
#include <iomanip>

#include  "console(v1.9).h"

using namespace std;
Console c;
const int SCREEN_WIDTH = 120;
const int INITIAL_Y = 0;

int getDisplayedRowByDepth(int maxDepth, int depthOfNodeToPrint) {
	if (depthOfNodeToPrint == 0) {
		return 0;
	}
	int acc = (int)pow(2, maxDepth - (depthOfNodeToPrint - 1));

	int depth = getDisplayedRowByDepth(maxDepth, depthOfNodeToPrint - 1) + acc;
	return depth;

}

int getMaxWidth(int depth) {
	return (int)pow(2, depth + 2) - 2;
}

void showTree(Node* root, int maxDepth) {
	if (root == NULL) {
		showEmptyTreeMessage();
	}
	else {
		int maxWidth = getMaxWidth(maxDepth);
		resizeScreen(maxWidth, getDisplayedRowByDepth(maxDepth, maxDepth));
		gotoxy(maxWidth / 2 + maxDepth, INITIAL_Y);
		printNode(root, maxWidth / 2 + maxDepth, INITIAL_Y, maxDepth);
		_getch();
		clrscr();
	}
}

void showEmptyTreeMessage() {
	cout << endl << endl << endl << endl << endl << endl
		<< "L'arbre est vide!"
		<< endl << endl << endl << endl;
	_getch();
	clrscr();
}

void resizeScreen(int maxWidth, int maxHeight)
{
	int cols = c.get_wColumn();
	int rows = c.get_wLines();
	int x = maxWidth + 5 > cols ? maxWidth + 5 + 1 : cols;
	int y = maxHeight + 1 > rows ? maxHeight + 1 : rows;
	c.set_wSize(x, y);
}

void printRightLink(int& x, int& y, int stopAt)
{
	gotoxy(++x, ++y);
	while (y < stopAt) {
		cout << '\\';
		gotoxy(++x, ++y);
	}
}

void printLeftLink(int& x, int& y, int stopAt)
{
	gotoxy(--x, ++y);
	while (y < stopAt) {
		cout << '/';
		gotoxy(--x, ++y);
	}
}

void printNode(Node* node, int x, int y, int maxDepth, int nodeDepth) {
	cout << node->value << "<" << node->height;
	int nextRowToPrint = getDisplayedRowByDepth(maxDepth, nodeDepth + 1);
	if (node->left != NULL) {
		int leftX = x, leftY = y;
		printLeftLink(leftX, leftY, nextRowToPrint);
		gotoxy(--leftX, leftY);
		cout << setw(2) << right;
		printNode(node->left, leftX, leftY, maxDepth, nodeDepth + 1);
	}
	if (node->right != NULL) {
		int rightX = x + 1, rightY = y;
		printRightLink(rightX, rightY, nextRowToPrint);
		gotoxy(rightX, rightY);
		cout << setw(2) << left;
		printNode(node->right, rightX, rightY, maxDepth, nodeDepth + 1);
	}
}