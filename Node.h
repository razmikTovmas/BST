#pragma once
class Node
{
public:
    Node(int v)
        : value(v)
        , left(nullptr)
        , right(nullptr)
        , parent(nullptr)
    { }
    ~Node() = default;

    int GetValue() { return value; }
    void SetValue(int v) { value = v; }
    Node* GetLeft() { return left; }
    void SetLeft(Node* l) { left = l; }
    Node* GetRight() { return right; }
    void SetRight(Node* r) { right = r; }
    Node* GetParent() { return parent; }
    void SetParent(Node* p) { parent = p; }

private:
    int value;
    Node* left;
    Node* right;
    Node* parent;
};
