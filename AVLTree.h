#pragma once
#include "BinaryTree.h"
#include "AVLNode.h"

class AVLTree : public BinaryTree
{
public:
    AVLTree() = default;
    ~AVLTree() = default;
    virtual void Insert(int);
    virtual void Remove(int);

private:
    virtual void BalanceHelper(Node*);
    int Height(Node*);
    int Balance(Node*);
};
