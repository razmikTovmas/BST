#include "AVLTree.h"
#include <algorithm>

Node* AVLTree::Insert(int value)
{
    Node* node = InsertHelper(root, new AVLNode(value));
    if (node == nullptr) {
        return nullptr;
    }

    return BalanceHelper(node->GetParent());
}

Node* AVLTree::Remove(int value)
{
    Node* node = RemoveHelper(FindNode(root, value));
    if (node == nullptr) {
        return nullptr;
    }

    return BalanceHelper(node);
}

Node* AVLTree::BalanceHelper(Node* node)
{
    if (node == nullptr) {
        return nullptr;
    }

    AVLNode* avlNode = dynamic_cast<AVLNode*> (node);

    // Update height of this node
    avlNode->SetHeight(1 + std::max(Height(avlNode->GetLeft()), Height(avlNode->GetRight())));

    // Get the balance of this node
    int balance = Balance(avlNode);

    if (balance > 1) {
        int childBalance = Balance(dynamic_cast<AVLNode*> (node->GetLeft()));
        if (childBalance >= 0) {
            // Left - Left Case
            RightRotation(node->GetLeft());
        } else {
            // Left - Right Case
            LeftRotation(node->GetLeft()->GetRight());
            RightRotation(node->GetLeft());
        }

        dynamic_cast<AVLNode*> (node)->SetHeight(1 + std::max(Height(node->GetLeft()), Height(node->GetRight())));
    } else if (balance < -1) {
        int childBalance = Balance(dynamic_cast<AVLNode*> (node->GetRight()));
        if (childBalance <= 0) {
            // Right - Right Case
            LeftRotation(node->GetRight());
        } else {
            // Right - Left Case
            RightRotation(node->GetRight()->GetLeft());
            LeftRotation(node->GetRight());
        }

        dynamic_cast<AVLNode*> (node)->SetHeight(1 + std::max(Height(node->GetLeft()), Height(node->GetRight())));
    }

    if (node->GetParent() == nullptr) {
        return node;
    }
    return BalanceHelper(node->GetParent());
}

int AVLTree::Height(Node* node)
{
    return (node == nullptr) ? 0 : dynamic_cast<AVLNode*> (node)->GetHeight();
}

int AVLTree::Balance(Node* node)
{
    return (node == nullptr) ? 0 : Height(node->GetLeft()) - Height(node->GetRight());
}
