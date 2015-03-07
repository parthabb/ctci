// LL CPP file.

#include <iostream>
#include "node.h"
#include "ll.h"

using namespace std;

ll :: ll () {
    m_head = NULL;
}

ll :: ~ll() {
    Node * curr = m_head, * next;
    while (curr != NULL) {
        next = curr->getNext();
        delete curr;
        curr = next;
    }
}

void ll :: insert (int el) {
    Node * n = new Node (el);
    Node * temp = m_head;
    if (m_head == NULL) {
        m_head = n;
    } else {
        while (temp->getNext() != NULL) temp = temp->getNext();
        temp->setNext(n);
    }
}

void ll :: del (int el) {
    if (m_head == NULL) {
        return;
    } else {
        Node * temp = m_head;
        Node * prev = temp;
        while (temp != NULL) {
            if (temp->getVal() == el) {
                if (temp == m_head) {
                    m_head = temp->getNext();
                } else {
                    prev->setNext(temp->getNext());
                }
                delete temp;
                prev = NULL;
                delete prev;
                break;
            }
            prev = temp;
            temp = temp->getNext();
        }
    }
}

bool ll :: find (int el) {
    Node * temp = m_head;
    while(temp != NULL) {
        if (temp->getVal() == el) {
            return true;
        }
        temp = temp->getNext();
    }
    return false;
}

void ll :: print () {
    Node * temp = m_head;
    while (temp != NULL) {
        cout << temp->getVal() << '\t';
        temp = temp->getNext();
    }
    cout << endl;
}

void ll :: remove_dups () {
    Node * curr = m_head, * temp1, * prev;
    while (curr != NULL) {
        prev = curr;
        temp1 = curr->getNext();
        while (temp1 != NULL) {
            if (temp1->getVal() == curr->getVal()) {
                prev->setNext(temp1->getNext());
                Node * temp2 = temp1;
                temp1 = temp1->getNext();
                delete temp2;
            } else {
                prev = temp1;
                temp1 = temp1->getNext();
            }
        }
        curr = curr->getNext();
    }
}


Node * ll :: kth_to_last (int k) {
    Node * temp = m_head;
    Node * k_th = m_head;
    while (temp->getNext() != NULL) {
        if (k == 1) {
            k_th = k_th->getNext();
        } else {
            k--;
        }
        temp = temp->getNext();
    }
    cout << k_th->getVal() << endl;
    temp = NULL;
    delete temp;
    return k_th;
}

void ll :: reverse () {
    Node * prev, * curr, * next;
    prev = m_head;
    curr = prev->getNext();
    next = curr->getNext();
    prev->setNext(NULL);
    while (next != NULL) {
        curr->setNext(prev);
        prev = curr;
        curr = next;
        next = next->getNext();
    }
    curr->setNext(prev);
    m_head = curr;
    prev = NULL;
    delete prev;
    curr = NULL;
    delete curr;
    next = NULL;
    delete next;
}

void ll :: partition (int val) {
    Node * i, * j;
    i = m_head;
    while (i->getNext() != NULL) {
        if (i->getVal() == val) {
            j = i;
        }
        i = i->getNext();
    }
    int temp = i->getVal();
    i->setVal(j->getVal());
    j->setVal(temp);

    i = m_head;
    j = m_head;
    while (i->getNext() != NULL) {
        if (i->getVal() < val) {
            temp = j->getVal();
            j->setVal(i->getVal());
            i->setVal(temp);
            j = j->getNext();
        }
        i = i->getNext();
    }
    temp = i->getVal();
    i->setVal(j->getVal());
    j->setVal(temp);
    i = NULL;
    delete i;
    j = NULL;
    delete j;
}


Node * ll :: getFirstEl () {
   return m_head;
}