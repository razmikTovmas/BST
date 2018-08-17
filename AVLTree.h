#pragma once
#include "BinaryTree.h"
#include "AVLNode.h"

class AVLTree : public BinaryTree
{
private:
	virtual Node * BalanceHelper(Node *);
	int Height(Node *);
	int Max(int a, int b);
	int Balance(Node *);
public:
	AVLTree();
	~AVLTree();
	virtual Node * Insert(int);
	virtual Node * Remove(int);
};
