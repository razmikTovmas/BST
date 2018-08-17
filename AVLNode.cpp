#include "stdafx.h"
#include "AVLNode.h"

AVLNode::AVLNode(int value) :Node(value), height(1) { }
AVLNode::~AVLNode() { }

int AVLNode::GetHeight() { return height; }
void AVLNode::SetHeight(int h) { height = h; }
