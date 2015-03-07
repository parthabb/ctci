#include "bst.h"

void BST :: AddNode(int val) {
    BinaryTreeNode * temp = new BinaryTreeNode();
    temp->SetVal(val);
    BinaryTreeNode * curr;
    if (root == 0) {
        root = temp;
    } else {
        BinaryTreeNode * next_free_node;
        curr = root;
        while (curr != 0) {
            next_free_node = curr;
            if (curr->GetVal() > val) curr = curr->GetLeftChild();
            else curr = curr->GetRightChild();
        }
        if (next_free_node->GetVal() > val) next_free_node->AddLeftChild(temp);
        else next_free_node->AddRightChild(temp);
    }
}