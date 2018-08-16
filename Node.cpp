#include "stdafx.h"
#include "Node.h"


Node::Node(int v) : value(v), left(nullptr), right(nullptr), parent(nullptr) { }
Node::~Node() { }

int Node::GetValue() { return value; }
void Node::SetValue(int v) { value = v; }
Node * Node::GetLeft() { return left; }
void Node::SetLeft(Node * l) { left = l; }
Node * Node::GetRight() { return right; }
void Node::SetRight(Node * r) { right = r; }
Node * Node::GetParent() { return parent; }
void Node::SetParent(Node * p) { parent = p; }
