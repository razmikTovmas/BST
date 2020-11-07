#pragma once
#include "Node.h"

class RBNode : public Node
{
public:
    RBNode(int value)
        : Node(value)
        , color(true)
    {}

    ~RBNode() = default;

    void SetBlack() { color = false; }
    void SetRed() { color = true; }
    bool IsBlack() { return !color; }
    bool IsRed() { return color; }
    void ReColor() { color = !color; }

private:
    bool color; /* Red - true, Black - false */
};
