#include "BinaryTree.h"
#include <iostream>

BinaryTree::BinaryTree() : root(nullptr) { }
BinaryTree::~BinaryTree() { }

void BinaryTree::Insert(int value)
{
    InsertHelper(root, new Node(value));
}

Node* BinaryTree::InsertHelper(Node* node, Node* nodeToInsert)
{
    if (root == nullptr) {
        root = nodeToInsert;
        return nodeToInsert;
    } else {
        while (true) {
            if (nodeToInsert->GetValue() < node->GetValue()) {
                if (node->GetLeft() == nullptr) {
                    node->SetLeft(nodeToInsert);
                    nodeToInsert->SetParent(node);
                    return nodeToInsert;
                } else {
                    node = node->GetLeft();
                }
            } else if (nodeToInsert->GetValue() > node->GetValue()) {
                if (node->GetRight() == nullptr) {
                    node->SetRight(nodeToInsert);
                    nodeToInsert->SetParent(node);
                    return nodeToInsert;
                } else {
                    node = node->GetRight();
                }
            } else {
                delete nodeToInsert;
                return nullptr;
            }
        }
    }

    if (nodeToInsert->GetValue() < node->GetValue()) {
        if (node->GetLeft() == nullptr) {
            node->SetLeft(nodeToInsert);
            nodeToInsert->SetParent(node);
        } else {
            node->SetLeft(InsertHelper(node->GetLeft(), nodeToInsert));
        }
    } else if (nodeToInsert->GetValue() > node->GetValue()) {
        if (node->GetRight() == nullptr) {
            node->SetRight(nodeToInsert);
            nodeToInsert->SetParent(node);
        } else {
            node->SetRight(InsertHelper(node->GetRight(), nodeToInsert));
        }
    }

    return node;
}

void BinaryTree::Remove(int value)
{
    RemoveHelper(FindNode(root, value));
}

Node* BinaryTree::RemoveHelper(Node* node)
{
    if (node == nullptr) {
        return nullptr;
    }

    if (node->GetLeft() != nullptr && node->GetRight() != nullptr) {
        // Case 4: The value to remove has both a left and right subtree
        Node* minNode = FindMin(node->GetRight());

        node->SetValue(minNode->GetValue());
        node = minNode;
    }

    Node* parent = node->GetParent();

    if (node->GetLeft() == nullptr && node->GetRight() == nullptr) {
        //  Case 1: The value to remove is a leaf node
        if (node == root){
            root = nullptr;
        } else {
            if (node == parent->GetLeft()) {
                node->GetParent()->SetLeft(nullptr);
            } else {
                node->GetParent()->SetRight(nullptr);
            }
        }
    } else if (node->GetRight() != nullptr) {
        // Case 2: The value to remove has a right subtree, but no left subtree
        if (node == root) {
            root = node->GetRight();
            root->SetParent(nullptr);
        } else {
            if (node == parent->GetLeft()) {
                parent->SetLeft(node->GetRight());
                node->GetRight()->SetParent(parent);
            } else {
                parent->SetRight(node->GetRight());
                node->GetRight()->SetParent(parent);
            }
        }
    } else {
        // Case 3: The value to remove has a left subtree, but no right subtree
        if (node == root) {
            root = node->GetLeft();
            root->SetParent(nullptr);
        } else {
            if (node == parent->GetLeft()) {
                parent->SetLeft(node->GetLeft());
                node->GetLeft()->SetParent(parent);
            } else {
                parent->SetRight(node->GetLeft());
                node->GetLeft()->SetParent(parent);
            }
        }
    }

    delete node;
    return parent;
}

bool BinaryTree::Contains(int value)
{
    return FindNode(root, value) != nullptr;
}

Node* BinaryTree::FindNode(Node* node, int value)
{
    if (node == nullptr || value == node->GetValue()) {
        return node;
    }

    if (value < node->GetValue()) {
        return FindNode(node->GetLeft(), value);
    } else {
        return FindNode(node->GetRight(), value);
    }
}

Node* BinaryTree::FindMin(Node* node)
{
    if (node->GetLeft() == nullptr) {
        return node;
    } else {
        return FindMin(node->GetLeft());
    }
}

void BinaryTree::Inorder()
{
    InorderHelper(root);
    std::cout << std::endl;
}

void BinaryTree::Preorder()
{
    PreorderHelper(root);
    std::cout << std::endl;
}

void BinaryTree::Postorder()
{
    PostorderHelper(root);
    std::cout << std::endl;
}

void BinaryTree::InorderHelper(Node* node)
{
    if (node != nullptr) {
        InorderHelper(node->GetLeft());
        std::cout << node->GetValue() << "  ";
        InorderHelper(node->GetRight());
    }
}

void BinaryTree::PreorderHelper(Node* node)
{
    if (node != nullptr) {
        std::cout << node->GetValue() << "  ";
        PreorderHelper(node->GetLeft());
        PreorderHelper(node->GetRight());
    }
}

void BinaryTree::PostorderHelper(Node* node)
{
    if (node != nullptr) {
        PostorderHelper(node->GetLeft());
        PostorderHelper(node->GetRight());
        std::cout << node->GetValue() << "  ";
    }
}

void BinaryTree::LeftRotation(Node* x)
{
    Node* y = x->GetParent();

    if (y == nullptr) {
        return;
    }

    if (y == root) {
        root = x;
    }

    if (y->GetParent() != nullptr) {
        if (y->GetParent()->GetLeft() == y) {
            y->GetParent()->SetLeft(x);
        } else {
            y->GetParent()->SetRight(x);
        }
    }

    x->SetParent(y->GetParent());
    y->SetParent(x);
    y->SetRight(x->GetLeft());
    if (y->GetRight() != nullptr) {
        y->GetRight()->SetParent(y);
    }
    x->SetLeft(y);
}

void BinaryTree::RightRotation(Node* x)
{
    Node* y = x->GetParent();

    if (y == nullptr) {
        return;
    }

    if (y == root) {
        root = x;
    }

    if (y->GetParent() != nullptr) {
        if (y->GetParent()->GetLeft() == y) {
            y->GetParent()->SetLeft(x);
        } else {
            y->GetParent()->SetRight(x);
        }
    }

    x->SetParent(y->GetParent());
    y->SetParent(x);
    y->SetLeft(x->GetRight());
    if (y->GetLeft() != nullptr) {
        y->GetLeft()->SetParent(y);
    }
    x->SetRight(y);
}

void BinaryTree::BalanceHelper(Node* node)
{
    return;
}
