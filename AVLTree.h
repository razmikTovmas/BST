#pragma once
#include "BinaryTree.h"
#include "AVLNode.h"

class AVLTree : public BinaryTree
{
private:
	virtual void BalanceHelper(Node *);
	int Height(Node *);
	int Max(int a, int b);
	int Balance(Node *);
public:
	AVLTree();
	~AVLTree();
	virtual void Insert(int);
	virtual void Remove(int);
};
