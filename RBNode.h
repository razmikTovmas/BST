#pragma once
#include "Node.h"

class RBNode : public Node
{
private:
	bool color; /* Red - true, Black - false */
public:
	RBNode(int);
	~RBNode();
	void SetBlack();
	void SetRed();
	bool IsBlack();
	bool IsRed();
	void ReColor();
};
