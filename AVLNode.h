#pragma once
#include "Node.h"

class AVLNode : public Node
{
public:
    AVLNode(int value)
        : Node(value)
        , height(1)
    { }
    ~AVLNode() = default;

    int GetHeight() { return height; }
    void SetHeight(int h) { height = h; }
private:
    int height;
};
