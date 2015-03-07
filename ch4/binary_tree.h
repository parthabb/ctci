#ifndef __binary_tree_h__
#define __binary_tree_h__

#include "bin_tree_node.h"

class BinaryTree {
protected:
    BinaryTreeNode * root;
public:
    BinaryTree();
    ~BinaryTree();
    void AddNode(int val);
    void InOrderTraversal();
    void PreOrderTraversal();
    void PostOrderTraversal();
};

#endif
