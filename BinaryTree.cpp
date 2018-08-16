#include "stdafx.h"
#include "BinaryTree.h"


BinaryTree::BinaryTree() : root(nullptr) { }
BinaryTree::~BinaryTree() { }

Node * BinaryTree::Insert(int value)
{
	return InsertHelper(root, new Node(value));
}

Node * BinaryTree::InsertHelper(Node * node, Node * nodeToInsert)
{
	if (root == nullptr)
	{
		root = nodeToInsert;
		return nodeToInsert;
	}
	else
	{
		while (true)
		{
			if (nodeToInsert->GetValue() < node->GetValue())
			{
				if (node->GetLeft() == nullptr)
				{
					node->SetLeft(nodeToInsert);
					nodeToInsert->SetParent(node);
					return nodeToInsert;
				}
				else
				{
					node = node->GetLeft();
				}
			}
			else if (nodeToInsert->GetValue() > node->GetValue())
			{
				if (node->GetRight() == nullptr)
				{
					node->SetRight(nodeToInsert);
					nodeToInsert->SetParent(node);
					return nodeToInsert;
				}
				else
				{
					node = node->GetRight();
				}
			}
			else
			{
				delete nodeToInsert;
				return node;
			}
		}
	}


	if (nodeToInsert->GetValue() < node->GetValue())
	{
		if (node->GetLeft() == nullptr)
		{
			node->SetLeft(nodeToInsert);
			nodeToInsert->SetParent(node);
		}
		else
		{
			node->SetLeft(InsertHelper(node->GetLeft(), nodeToInsert));
		}
	}
	else if (nodeToInsert->GetValue() > node->GetValue())
	{
		if (node->GetRight() == nullptr)
		{
			node->SetRight(nodeToInsert);
			nodeToInsert->SetParent(node);
		}
		else
		{
			node->SetRight(InsertHelper(node->GetRight(), nodeToInsert));
		}
	}

	return node;
}

bool BinaryTree::Contains(int value)
{
	return FindNode(root, value) != nullptr;
}

Node * BinaryTree::FindNode(Node * node, int value)
{
	if (node == nullptr || value == node->GetValue()) return node;

	if (value < node->GetValue())
	{
		return FindNode(node->GetLeft(), value);
	}
	else // if (value > node->GetValue())
	{
		return FindNode(node->GetRight(), value);
	}
}

Node * BinaryTree::FindMin(Node * node)
{
	if (node->GetLeft() == nullptr)
	{
		return node;
	}
	else
	{
		return FindMin(node->GetLeft());
	}
}
