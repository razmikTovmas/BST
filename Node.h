#pragma once
class Node
{
private:
	int value;
	Node * left;
	Node * right;
	Node * parent;

public:
	int GetValue();
	void SetValue(int);
	Node * GetLeft();
	void SetLeft(Node *);
	Node * GetRight();
	void SetRight(Node *);
	Node * GetParent();
	void SetParent(Node *);
	Node(int);
	virtual ~Node();
};
