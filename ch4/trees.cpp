#include <iostream>
#include "binary_tree.h"
#include "bst.h"
#include "graph.h"

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
    
    Graph * g = new Graph();
    Node * n[10];
    for (int i = 0; i < 10; i++) {
        n[i] = new Node();
        n[i]->SetVal(i + 1);
        g->AddNode(n[i]);
    }
    g->AddEdge(n[0], n[1]);
    g->AddEdge(n[1], n[2]);
    g->AddEdge(n[2], n[3]);
    g->AddEdge(n[0], n[4]);
    g->AddEdge(n[3], n[4]);
    g->AddEdge(n[4], n[5]);
    g->AddEdge(n[5], n[4]);
    g->AddEdge(n[5], n[6]);
    g->AddEdge(n[8], n[5]);
    g->AddEdge(n[9], n[8]);
    delete g;
}
