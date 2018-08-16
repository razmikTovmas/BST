#include "stdafx.h"
#include "BinaryTree.h"
#include <iostream>

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

Node * BinaryTree::Remove(int value)
{
	return RemoveHelper(FindNode(root, value));
}

Node * BinaryTree::RemoveHelper(Node * node)
{
	if (node == nullptr) return nullptr;

	if (node->GetLeft() != nullptr && node->GetRight() != nullptr)
	// Case 4: The value to remove has both a left and right subtree
	{
		Node * minNode = FindMin(node->GetRight());

		node->SetValue(minNode->GetValue());
		node = minNode;
	}

	Node * parent = node->GetParent();

	if (node->GetLeft() == nullptr && node->GetRight() == nullptr)
	//  Case 1: The value to remove is a leaf node
	{
		if (node == root)
		{
			root = nullptr;
		}
		else
		{
			if (node == parent->GetLeft())
			{
				node->GetParent()->SetLeft(nullptr);
			}
			else
			{
				node->GetParent()->SetRight(nullptr);
			}
		}
	}
	else if (node->GetRight() != nullptr)
	// Case 2: The value to remove has a right subtree, but no left subtree
	{
		if (node == root)
		{
			root = node->GetRight();
		}
		else
		{
			if (node == parent->GetLeft())
			{
				parent->SetLeft(node->GetRight());
				node->GetRight()->SetParent(parent);
			}
			else
			{
				parent->SetRight(node->GetRight());
				node->GetRight()->SetParent(parent);
			}
		}
	}
	else // if(node.Left != null)
	// Case 3: The value to remove has a left subtree, but no right subtree
	{
		if (node == root)
		{
			root = node->GetLeft();
		}
		else
		{
			if (node == parent->GetLeft())
			{
				parent->SetLeft(node->GetLeft());
				node->GetLeft()->SetParent(parent);
			}
			else
			{
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

void BinaryTree::InorderHelper(Node * node)
{
	if (node != nullptr)
	{
		InorderHelper(node->GetLeft());
		std::cout << node->GetValue() << "  ";
		InorderHelper(node->GetRight());
	}
}

void BinaryTree::PreorderHelper(Node * node)
{
	if (node != nullptr)
	{
		std::cout << node->GetValue() << "  ";
		PreorderHelper(node->GetLeft());
		PreorderHelper(node->GetRight());
	}
}

void BinaryTree::PostorderHelper(Node * node)
{
	if (node != nullptr)
	{
		PostorderHelper(node->GetLeft());
		PostorderHelper(node->GetRight());
		std::cout << node->GetValue() << "  ";
	}
}
