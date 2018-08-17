#include "stdafx.h"
#include "RBTree.h"

/**
 *	1 - Every node is RED or BLACK
 *	2 - Root is always BLACK
 *	3 - New insertions are always RED
 *	4 - Every path from root to leaf has the same number of BLACK nodes
 *	5 - No path can have two consecutive RED nodes
 *	6 - Nulls are BLACK
 */

RBTree::RBTree() : BinaryTree() { }
RBTree::~RBTree() { }
