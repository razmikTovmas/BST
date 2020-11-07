#pragma once
#include "BinaryTree.h"
#include "RBNode.h"

class RBTree : public BinaryTree
{
public:
    RBTree() = default;
    ~RBTree() = default;
    Node* Insert(int) override;
    Node* Remove(int) override;

private:
    Node* BalanceHelper(Node*) override;
    Node* RemoveBalance(Node*);
};
