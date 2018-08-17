#pragma once
#include "Node.h"
class AVLNode : public Node
{
private:
	int height;
public:
	AVLNode(int);
	~AVLNode();
	int GetHeight();
	void SetHeight(int);
};
