#include "RBTree.h"

/**
 *	1 - Every node is RED or BLACK
 *	2 - Root is always BLACK
 *	3 - New insertions are always RED
 *	4 - Every path from root to leaf has the same number of BLACK nodes
 *	5 - No path can have two consecutive RED nodes
 *	6 - Nulls are BLACK
 */

Node* RBTree::Insert(int value)
{
    Node* node = InsertHelper(root, new RBNode(value));
    if (node == nullptr) {
        return nullptr;
    }

    BalanceHelper(node);
    return node;
}

Node* RBTree::BalanceHelper(Node* n)
{
    RBNode* node = dynamic_cast<RBNode*> (n);

    if (n == root) {
        node->SetBlack();
        return n;
    }

    Node* parent = n->GetParent();
    if (dynamic_cast<RBNode*> (parent)->IsBlack()) {
        return n;
    }

    Node* uncle = nullptr;

    if (parent->GetParent()->GetLeft() == parent) {
        uncle = parent->GetParent()->GetRight();
    } else {
        uncle = parent->GetParent()->GetLeft();
    }

    bool uncleColor = false;

    if (uncle == nullptr) {
        uncleColor = false;
    } else {
        uncleColor = dynamic_cast<RBNode*> (uncle)->IsRed();
    }

    if (uncleColor == true) {
        dynamic_cast<RBNode*> (parent)->SetBlack();
        dynamic_cast<RBNode*> (uncle)->SetBlack();
        dynamic_cast<RBNode*> (parent->GetParent())->SetRed();
        n = parent->GetParent();
        n = BalanceHelper(n);
    } else {
        if (parent == parent->GetParent()->GetLeft()) {
            if (node == parent->GetLeft()) {
                //Left - Left Case
                dynamic_cast<RBNode*> (parent->GetParent())->SetRed();
                dynamic_cast<RBNode*> (parent)->SetBlack();

                RightRotation(parent);
            } else {
                // Left - Right Case
                dynamic_cast<RBNode*> (parent->GetParent())->SetRed();
                node->SetBlack();

                LeftRotation(n);
                RightRotation(parent);
            }
        } else {
            if (node == parent->GetLeft()) {
                //Right - Left Case
                dynamic_cast<RBNode*> (parent->GetParent())->SetRed();
                node->SetBlack();

                RightRotation(n);
                LeftRotation(parent);
            } else {
                // Right - Right Case
                dynamic_cast<RBNode*> (parent->GetParent())->SetRed();
                dynamic_cast<RBNode*> (parent)->SetBlack();

                LeftRotation(parent);
            }
        }
    }

    return n;
}

Node* RBTree::Remove(int value)
{
    return nullptr;
}

Node* RBTree::RemoveBalance(Node* node)
{
    return nullptr;
}
