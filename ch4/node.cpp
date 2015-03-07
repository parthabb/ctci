#include <iostream>
#include "node.h"

Node :: Node () : m_val (0){}

void Node :: SetVal (int val) {
    m_val = val;
}

int Node :: GetVal () {
    return m_val;
}

void Node :: AddChild (Node * n) {
    m_children.push_back(n);
}

std::vector <Node *> Node :: GetChildren() {
    return m_children;
}

Node :: ~Node() {
    std::cout << "Calling Node Destructor" << std::endl;
    for (int i = m_children.size() - 1; i >= 0; i--) {
        Node * n = m_children[i];
        m_children.erase(m_children.begin() + i);
        delete n;
    }
}