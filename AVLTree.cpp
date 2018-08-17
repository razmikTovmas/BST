#include "stdafx.h"
#include "AVLTree.h"

AVLTree::AVLTree() { }
AVLTree::~AVLTree() { }

Node * AVLTree::Insert(int value)
{
	Node * node = InsertHelper(root, new AVLNode(value));

	BalanceHelper(node);

	return node;
}

Node * AVLTree::Remove(int value)
{
	Node * node = RemoveHelper(FindNode(root, value));

	BalanceHelper(node);

	return node;
}

Node * AVLTree::BalanceHelper(Node * node)
{
	return node;
}

int AVLTree::Height(Node * node) { return (node == nullptr) ? 0 : dynamic_cast<AVLNode *> (node)->GetHeight(); }
int AVLTree::Max(int a, int b) { return (a > b) ? a : b; }
int AVLTree::Balance(Node * node) { return (node == nullptr) ? 0 : Height(node->GetLeft()) - Height(node->GetRight()); }
