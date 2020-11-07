#pragma once
#include "BinaryTree.h"
#include "RBNode.h"

class RBTree : public BinaryTree
{
public:
    RBTree() = default;
    ~RBTree() = default;
    virtual Node* Insert(int);
    virtual Node* Remove(int);

private:
    virtual Node* BalanceHelper(Node*);
    Node* RemoveBalance(Node*);
};
