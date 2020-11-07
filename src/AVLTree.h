#pragma once
#include "BinaryTree.h"
#include "AVLNode.h"

class AVLTree : public BinaryTree
{
public:
    AVLTree() = default;
    ~AVLTree() = default;
    virtual Node* Insert(int);
    virtual Node* Remove(int);

private:
    virtual Node* BalanceHelper(Node*);
    int Height(Node*);
    int Balance(Node*);
};
