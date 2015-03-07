// Node for linked list.

#ifndef __NODE__
#define __NODE__

class Node {
private:
    int m_el;
    Node * m_next;
public:
    Node(int el);
    Node * getNext();
    void setNext(Node * n);
    int getVal();
    void setVal(int el);
};

#endif
