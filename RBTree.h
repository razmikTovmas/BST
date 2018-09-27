#pragma once
#include "BinaryTree.h"
#include "RBNode.h"

class RBTree : public BinaryTree
{
private:
	virtual Node * BalanceHelper(Node *);
	Node * RemoveBalance(Node *);
public:
	RBTree();
	~RBTree();
	virtual Node * Insert(int);
	virtual Node * Remove(int);
};

