#ifndef __bin_tree_node_h__
#define __bin_tree_node_h__

#include "node.h"

class BinaryTreeNode : public Node {
public:
    BinaryTreeNode ();
    void AddLeftChild(BinaryTreeNode *);
    void AddRightChild(BinaryTreeNode *);
    BinaryTreeNode * GetLeftChild();
    BinaryTreeNode * GetRightChild();
};

#endif
