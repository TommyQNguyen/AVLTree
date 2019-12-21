#include "main.h"

using namespace std;

Node* root = NULL;

int main() {

	// init();
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	int choice = 0;
	while (choice != MENU_QUIT)
	{
		cvmSetColor(CYAN);
		choice = showMenu();
		switch (choice)
		{
		case MENU_ADD:
			menu_ADD();
			break;
		case MENU_PRINT:
			showTree();
			break;
		case MENU_DELETE: {
			menu_DELETE();
			break;
		}
		case MENU_TRAVERSAL:
			menu_TRAVERSAL(root);
			break;
		}
		cvmResetColor();
	}
}

void init()
{
	insert(5);
	insert(1);
	insert(7);
	insert(6);
	insert(-1);
	insert(4);
	insert(9);
	insert(8);
	insert(10);
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
		}
		else
			insert(n->left, value);
	}
	if (value > n->value) {
		if (n->right == nullptr) {
			n->right = new Node;
			n->right->value = value;
		}
		else
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

Node* findParent(Node* root, int valueToFind) 
{
	if (root->left != nullptr && root->left->value == valueToFind) 
	{
		return root;
	}
	if (root->right != nullptr && root->right->value == valueToFind) 
	{
		return root;
	}
	if (valueToFind < root->left->value) 
	{
		return findParent(root->left, valueToFind);
	}
	if (valueToFind > root->right->value) 
	{
		return findParent(root->right, valueToFind);
	}
	return root;
}

void remove(Node& n, int value) 
{
	Node* nPointer;
	nPointer = &n;
	n.value = findSmallest(findValue(nPointer, value)->right)->value;
	cout << n.value;
}

int height(Node* n) 
{
	if (n == nullptr) 
	{
		return 0;
	}

	return 1 + max(height(n->right), height(n->left));
}

void showTree() {
	cvmSetColor(VERT);
	showTree(root, height(root) - 1);
	cvmResetColor();
}

void rotation(Node* n) {
	if (n->left != nullptr) {

		if (n->left->right != nullptr) {
			leftRightRotation(n);
		}
		else {
			rightRotation(n);
		}
	}
	else {
		if (n->right->right != nullptr) {
			leftRotation(n);
		}
		else {
			rightLeftRotation(n);
		}
	}
}

void leftRotation(Node* n) {
	swap(n, n->right);
	Node* temp = n->right->right;
	n->left = new Node;
	n->left->value = temp->value;
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
	n->left->left = nullptr;
	swap(n->left, n->right);
	n->height -= 2;
	n->left->height--;
}

void leftRightRotation(Node* n) {
	Node* temp = n->left->right;
	n->left->left = new Node;
	n->left->left->value = temp->value;
	n->left->right = nullptr;
	n->left->height += 2;
	swap(n->left, n->left->left);
	rightRotation(n);
}

void rightLeftRotation(Node* n) {
	Node* temp = n->right->left;
	n->right->right = new Node;
	n->right->right->value = temp->value;
	n->right->left = nullptr;
	n->right->height -= 2;
	swap(n->right, n->right->right);
	leftRotation(n);
}

void deletion(int value) {
	deletion(root, value);
}

void deletion(Node* node, int value) {
	if (root->value == value) {
		deleteRootNode();
		return;
	}

	if (value < node->value) {
		if (node->left->value == value) {
			if (isLeafNode(node->left)) {
				node->left = nullptr;
			}
			else if (hasOneChild(node->left)) {
				if (node->left->right == nullptr) {
					swap(node->left, node->left->left);
					Node* temp = node->left->left;
					node->left->left = nullptr;
					delete temp;
					node->left->height--;
				}
				else {
					swap(node->left, node->left->right);
					Node* temp = node->left->right;
					node->left->right = nullptr;
					node->left->height++;
				}
			}
			else {
				Node* successor = getSuccessor(node->left->right);
				swap(node->left, successor);
				deleteSuccessor(root, value);
				if (successor->right != nullptr) {
					swap(successor, successor->right);
				}
				if (node->left->right == successor && isLeafNode(successor)) {
					node->left->right = nullptr;
				}
				updateHeight(node);
			}
		}
		else {
			deletion(node->left, value);
		}
	}
	else {
		if (node->right->value == value) {
			if (isLeafNode(node->right)) {
				node->right = nullptr;
			}
			else if (hasOneChild(node->right)) {
				if (node->right->right == nullptr) {
					swap(node->right, node->right->left);
					Node* temp = node->right->left;
					node->right->left = nullptr;
					delete temp;
					node->right->height--;
				}
				else {
					swap(node->right, node->right->right);
					Node* temp = node->right->right;
					node->right->right = nullptr;
					delete temp;
					node->right->height++;
				}
			}
			else {
				Node* successor = getSuccessor(node->right->right);
				swap(node->right, successor);
				deleteSuccessor(root, value);
				if (successor->right != nullptr) {
					swap(successor, successor->right);
				}
				if (node->right->right == successor && isLeafNode(successor)) {
					node->right->right = nullptr;
				}
				updateHeight(node);
			}
		}
		else {
			deletion(node->right, value);
		}
	}
	updateHeight(node);
	if (node->height == 2 || node->height == -2)
		rotation(node);
}

void deleteRootNode() {
	if (isLeafNode(root)) {
		root = nullptr;
	}
	else if (hasOneChild(root)) {
		if (root->left != nullptr) {
			swap(root, root->left);
			root->left = nullptr;
			root->height--;
		}
		else {
			swap(root, root->right);
			root->right = nullptr;
			root->height++;
		}
	}
	else {
		Node* successor = getSuccessor(root->right);
		cout << root->value;
		Node* parentOfSuccessor = getParentSuccessor(root->right, successor);

		swap(root, successor);

		if (parentOfSuccessor->left == successor) {
			parentOfSuccessor->left = nullptr;
			parentOfSuccessor->height--;
		}
		else {
			swap(successor, successor->right);
			successor->right = nullptr;
			parentOfSuccessor++;
		}
	}
}

Node* find(int value) {
	return findRecursive(root, value);
}

Node* findRecursive(Node* node, int value) {
	if (node->value == value) {
		return node;
	}

	if (value < node->value) {
		if (node->left == nullptr) {
			return nullptr;
		}
		else {
			return findRecursive(node->left, value);
		}
	}
	else {
		if (node->right == nullptr) {
			return nullptr;
		}
		else {
			return findRecursive(node->right, value);
		}
	}

	return nullptr;
}

Node* getSuccessor(Node* node) {
	if (node->left == nullptr)
		return node;
	return getSuccessor(node->left);
}

Node* getParentSuccessor(Node* root, Node* successor) {
	if (root->left == successor)
		return root;
	if (root->right == successor)
		return root;

	getParentSuccessor(root->left, successor);
	getParentSuccessor(root->right, successor);
}

void updateHeight(Node* node) {
	if (node == nullptr)
		return;
	node->height = height(node->left) - height(node->right);
	updateHeight(node->left);
	updateHeight(node->right);

}

void deleteSuccessor(Node* n, int value) {
	if (n == NULL)
		return;
	if (n->left != nullptr)
		if (n->left->value == value) {
			n->left = nullptr;
			return;
		}

	if (n->right != nullptr)
		if (n->right->value == value) {
			n->right = nullptr;
			return;
		}

	deleteSuccessor(n->left, value);
	deleteSuccessor(n->right, value);
}

void swap(Node* a, Node* b) {
	int temp = a->value;
	a->value = b->value;
	b->value = temp;
}

bool hasOneChild(Node* node) {
	return (node->left == nullptr && node->right != nullptr) || (node->left != nullptr && node->right == nullptr);
}

bool isLeafNode(Node* node) {
	return node->left == nullptr && node->right == nullptr;
}

void inorder(Node* root) {
	if (root != NULL) {
		inorder(root->left);
		cout << root->value << "->";
		inorder(root->right);
	}
}

void postorder(Node* root)
{
	if (root == nullptr)
		return;

	postorder(root->left);
	postorder(root->right);
	cout << root->value << "->";
}

void preorder(Node* root)
{
	if (root == NULL)
		return;

	cout << root->value << "->";
	preorder(root->left);
	preorder(root->right);
}