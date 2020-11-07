add_executable(Tree Tree.cxx)
target_link_libraries(Tree PRIVATE bst)

add_executable(AVLTree AVLTree.cxx)
target_link_libraries(AVLTree PRIVATE bst)

add_executable(RBTree RBTree.cxx)
target_link_libraries(RBTree PRIVATE bst)
