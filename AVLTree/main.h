#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "console(v1.9).h"
#include "tree.h"
#include "Vue.h"

const int MENU_ADD = 1, MENU_PRINT = 2, MENU_DELETE = 3, MENU_TRAVERSAL = 4, MENU_QUIT = 5;

void insert(int value);
void showTree();
void deletion(int value);
void postorder(Node* node);
void preorder(Node* node);
void inorder(Node* node);
void insert(Node* n, int value);
void remove(Node& n, int value);
Node* findValue(Node* n, int valueToFind);
Node* findSmallest(Node* n);
Node* findParent(Node* root, int valueToFind);
Node* getSuccessor(Node* node);
void updateHeight(Node* node);
void showTree();
int height(Node* n);
void init();
void rotation(Node* n);
void leftRotation(Node* n);
void rightRotation(Node* n);
void leftRightRotation(Node* n);
void rightLeftRotation(Node* n);
void deletion(Node* node, int value);
bool isLeafNode(Node* node);
bool hasOneChild(Node* node);
void deleteSuccessor(Node* n, int value);
void deleteRootNode();
Node* find(int value);
Node* findRecursive(Node* root, int value);
Node* getParentSuccessor(Node* root, Node* successor);
void swap(Node* a, Node* b);
void postorder(Node* node);
void preorder(Node* node);
void inorder(Node* node);