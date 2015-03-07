#include <iostream>
#include "binary_tree.h"
#include "bst.h"

using namespace std;

int main() {
    BinaryTree * bt = new BinaryTree();
    for (int i = 0; i < 10; i++) {
        bt->AddNode(i + 1);
    }
    bt->InOrderTraversal();
    bt->PreOrderTraversal();
    bt->PostOrderTraversal();
    delete bt;

    BST * bst = new BST();
    for (int i = 0; i < 10; i++) {
        bst->AddNode(i + 1);
    }
    bst->InOrderTraversal();
    bst->PreOrderTraversal();
    bst->PostOrderTraversal();
    delete bst;
}
