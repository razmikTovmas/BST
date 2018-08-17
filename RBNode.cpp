#include "stdafx.h"
#include "RBNode.h"

RBNode::RBNode(int value) : Node(value), color(true) {}
RBNode::~RBNode() { }

void RBNode::SetBlack() { color = false; }
void RBNode::SetRed() { color = true; }

bool RBNode::IsBlack() { return !color; }
bool RBNode::IsRed() { return color; }

void RBNode::ReColor() { color = !color; }
