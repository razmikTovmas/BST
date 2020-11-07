#include "AVLTree.h"

int main()
{
    AVLTree bt;

    bt.Insert(1);
    bt.Insert(5);
    bt.Insert(2);
    bt.Insert(3);
    bt.Insert(7);
    bt.Insert(10);
    bt.Insert(13);
    bt.Insert(8);
    bt.Insert(9);
    bt.Insert(0);

    bt.Inorder();
    bt.Remove(0);
    bt.Inorder();

    return 0;
}