#include "stdafx.h"
#include "Node.h"


Node::Node(int v) : value(v), left(nullptr), right(nullptr), parent(nullptr) { }
Node::~Node() { }
