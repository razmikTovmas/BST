project(bst)

set(Headers
    AVLNode.h
    AVLTree.h
    BinaryTree.h
    Node.h
    RBNode.h
    RBTree.h
)

set(Sources
    AVLTree.cpp
    BinaryTree.cpp
    RBTree.cpp
)

add_library(bst SHARED
    ${Headers} ${Sources}
)
