#include <iostream>
#include "console(v1.9).h"
#include "tree.h"

using namespace std;

const int MENU_ADD = 1, MENU_PRINT = 2, MENU_DELETE = 3, MENU_TRAVERSAL = 4, MENU_QUIT = 5;

void insert(Node* n, int value);
void insert(int value);
void remove(Node& n, int value);
Node* findValue(Node* n, int valueToFind);
Node* findSmallest(Node* n);
Node* findParent(Node* root, int valueToFind);
void showTree();
int height(Node* n);
void init();
int showMenu();
void menu_ADD();
void rotation(Node* n);
void leftRotation(Node* n);
void rightRotation(Node* n);
void swap(Node* a, Node* b);


Node* root = NULL;

int main() {

	init();
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	int choice = 0;
	while (choice != MENU_QUIT)
	{
		//showStack(first);
		choice = showMenu();
		switch (choice) 
		{
		case MENU_ADD:
			menu_ADD();
			break;
		case MENU_PRINT:
			showTree();
			break;
		case MENU_DELETE:
			//Delete
			break;
		case MENU_TRAVERSAL:
			//Traversal function
			break;
		}
	}
}

void init()
{
	/*insert(1);
	insert(2);
	insert(3);*/
}

void insert(Node* n, int value) {
	if (root == nullptr) {
		root = new Node;
		root->value = value;
		return;
	}

	if (value == n->value) {
		return;
	}
	if (value < n->value) {
		if (n->left == nullptr) {
			n->left = new Node;
			n->left->value = value;
		} else
			insert(n->left, value);
	}
	if (value > n->value) {
		if (n->right == nullptr) {
			n->right = new Node;
			n->right->value = value;
		} else
			insert(n->right, value);
	}

	n->height = height(n->left) - height(n->right);
	if (n->height == 2 || n->height == -2) 
		rotation(n);

	return; 
}

void insert(int value) 
{
	insert(root, value);
}

Node* findValue(Node* n, int valueToFind) {
	if (valueToFind == n->value) {
		return n;
	}
	if (valueToFind == n->left->value) {
		return n->left;
	}
	if (valueToFind == n->right->value) {
		return n->right;
	}
	if (valueToFind < n->value) {
		findValue(n->left, valueToFind);
	}
	if (valueToFind >= n->value) {
		findValue(n->right, valueToFind);
	}
	return n;
}
Node* findSmallest(Node* n) {
	if (n->left == nullptr) {
		return n;
	}
	return findSmallest(n->left);
}

Node* findParent(Node* root, int valueToFind) {
	cout << root->right->value;
	if (root->left != nullptr && root->left->value == valueToFind) {
		return root;
	}
	if (root->right != nullptr && root->right->value == valueToFind) {
		return root;
	}
	if (valueToFind < root->left->value) {
		return findParent(root->left, valueToFind);
	}
	if (valueToFind > root->right->value) {
		return findParent(root->right, valueToFind);
	}
	return root;
}

void remove(Node& n, int value) {
	Node* nPointer;
	nPointer = &n;
	n.value = findSmallest(findValue(nPointer, value)->right)->value;
	cout << n.value;
	//    findParent(n, findValue(n, findSmalets(nPointer)->value)->value)->left = nullptr;
}


int height(Node* n) {
	if (n == nullptr) {
		return 0;
	}
	
	return 1 + max(height(n->right), height(n->left));
}

void showTree() {
	cvmSetColor(VERT);
	showTree(root, height(root) - 1);
	cvmResetColor();
}

int showMenu() {
	int choice;
	cout << endl << endl <<
		"Le facteur d'equilibre est de : " << endl << endl <<
		"Que voulez-vous faire?" << endl << endl << endl <<
		"1 Ajouter un element a l'arbre?" << endl <<
		"2 Imprimer l'arbre?" << endl <<
		"3 Supprimer une valeur" << endl <<
		"4 Parcourir l'arbre" << endl <<
		"5 Quitter?" << endl << endl << endl << endl << endl << endl
		<< "Votre choix : ";
	cin >> choice;
	clrscr();
	return choice;
}

void menu_ADD()
{
	int dataInput = 0;

	clrscr();
	cvmSetColor(ROSE);
	cout << "\n\n\n\n\n\n\nQuelle est la valeur ? : ";
	cvmResetColor();
	cin >> dataInput;

	insert(dataInput);
	clrscr();
	showTree();
	clrscr();
}

void rotation(Node* n) {
	if (n->left == nullptr) {
		leftRotation(n);
	}
	else if (n->right == nullptr) {
		rightRotation(n);
	}
}

void leftRotation(Node* n) {
	swap(n, n->right);
	Node* temp = n->right->right;
	n->left = new Node;
	n->left->value = temp->value;
	delete n->right->right;
	n->right->right = nullptr;
	swap(n->left, n->right);
	n->height += 2;
	n->right->height++;
}

void rightRotation(Node* n) {
	swap(n, n->left);
	Node* temp = n->left->left;
	n->right = new Node;
	n->right->value = temp->value;
	delete n->left->left;
	n->left->left = nullptr;
	swap(n->left, n->right);
	n->height -= 2;
	n->left->height--;
}

void swap(Node* a, Node* b) {
	int temp = a->value;
	a->value = b->value;
	b->value = temp;
}