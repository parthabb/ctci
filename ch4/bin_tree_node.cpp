#include "bin_tree_node.h"

BinaryTreeNode :: BinaryTreeNode() : Node() {
    m_children.push_back(0);
    m_children.push_back(0);
}

void BinaryTreeNode :: AddLeftChild(BinaryTreeNode * n) {
    m_children[0] = (Node *)n;
}

void BinaryTreeNode :: AddRightChild(BinaryTreeNode * n) {
    m_children[1] = (Node *)n;
}

BinaryTreeNode * BinaryTreeNode :: GetLeftChild() {
    return (BinaryTreeNode *)m_children[0];
}

BinaryTreeNode * BinaryTreeNode :: GetRightChild() {
    return (BinaryTreeNode *)m_children[1];
}
