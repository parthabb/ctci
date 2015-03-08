#include <iostream>
#include "binary_tree.h"
#include <queue>
#include <stack>

BinaryTree :: BinaryTree() : root(0) {};

BinaryTree :: ~BinaryTree() {
    std::cout << "Calling BinaryTree destructor" << std::endl;
    std::stack<BinaryTreeNode *> s;
    BinaryTreeNode * curr = root;
    do {
        while (curr != 0) {
            if (curr->GetRightChild() != 0) s.push(curr->GetRightChild());
            s.push(curr);
            curr = curr->GetLeftChild();
        }
        curr = s.top();
        s.pop();
        if (curr->GetRightChild() != 0 && s.top() == curr->GetRightChild()) {
            s.pop();
            s.push(curr);
            curr = curr->GetRightChild();
        } else {
            BinaryTreeNode * temp = curr;
            curr = 0;
            delete temp;
        }
    } while (!s.empty());
}

void BinaryTree :: AddNode(int val) {
    BinaryTreeNode * temp = new BinaryTreeNode();
    temp->SetVal(val);
    if (root == 0) {
        root = temp;
    } else {
        BinaryTreeNode * next_free_node;
        std::queue<BinaryTreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            next_free_node = q.front();
            q.pop();
            if (next_free_node->GetLeftChild() == 0) break;
            q.push(next_free_node->GetLeftChild());
            if (next_free_node->GetRightChild() == 0) break;
            q.push(next_free_node->GetRightChild());
        }
        if (next_free_node->GetLeftChild() == 0) {
            next_free_node->AddLeftChild(temp);
        } else {
            next_free_node->AddRightChild(temp);
        }
    }
}

void BinaryTree :: InOrderTraversal() {
    std::cout << "Inorder" << std::endl;
    std::stack<BinaryTreeNode *> s;
    BinaryTreeNode * curr = root;
    do {
        if (curr != 0) {
            s.push(curr);
            curr = curr->GetLeftChild();
        } else {
            curr = s.top();
            s.pop();
            std::cout << curr->GetVal() << std::endl;
            curr = curr->GetRightChild();
        }
    } while (!s.empty() || curr != 0);
}

void BinaryTree :: PreOrderTraversal() {
    std::cout << "Preorder" << std::endl;
    std::stack<BinaryTreeNode *> s;
    BinaryTreeNode * curr;
    s.push(root);
    while (!s.empty()) {
        curr = s.top();
        s.pop();
        std::cout << curr->GetVal() << std::endl;
        if (curr->GetRightChild() != 0) s.push(curr->GetRightChild());
        if (curr->GetLeftChild() != 0) s.push(curr->GetLeftChild());
    }
}

void BinaryTree :: PostOrderTraversal() {
    std::cout << "Postorder" << std::endl;
    std::stack<BinaryTreeNode *> s;
    BinaryTreeNode * curr = root;
    do {
        while (curr != 0) {
            if (curr->GetRightChild() != 0) s.push(curr->GetRightChild());
            s.push(curr);
            curr = curr->GetLeftChild();
        }
        curr = s.top();
        s.pop();
        if (curr->GetRightChild() != 0 && s.top() == curr->GetRightChild()) {
            s.pop();
            s.push(curr);
            curr = curr->GetRightChild();
        } else {
            std::cout << curr->GetVal() << std::endl;
            curr = 0;
        }
    } while (!s.empty());
}