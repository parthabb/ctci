// Node CPP file.

#include <iostream>
#include "node.h"

using namespace std;

Node :: Node (int el) {
    m_next = NULL;
    m_el = el;
}

Node * Node :: getNext() {
    return m_next;
}

void Node :: setNext(Node * n) {
    m_next = n;
}

int Node :: getVal() {
    return m_el;
}

void Node :: setVal(int el) {
    m_el = el;
}
