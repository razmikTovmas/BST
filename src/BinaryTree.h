#pragma once
#include "Node.h"

class BinaryTree
{
private:
    void InorderHelper(Node*);
    void PreorderHelper(Node*);
    void PostorderHelper(Node*);

protected:
    Node* root;
    Node* FindNode(Node*, int);
    Node* FindMin(Node*);
    Node* InsertHelper(Node*, Node*);
    Node* RemoveHelper(Node*);
    void LeftRotation(Node*);
    void RightRotation(Node*);
    virtual Node* BalanceHelper(Node*);

public:
    BinaryTree();
    virtual ~BinaryTree();
    virtual Node* Insert(int);
    virtual Node* Remove(int);
    bool Contains(int);
    void Inorder();
    void Preorder();
    void Postorder();
};
