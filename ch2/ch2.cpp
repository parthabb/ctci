// Main file.

#include <iostream>
#include "node.h"
#include "ll.h"

using namespace std;

void del_node (Node * n) {
    Node * temp = n->getNext();
    n->setVal(temp->getVal());
    n->setNext(temp->getNext());
    delete temp;
}

ll * add (Node * l1, Node * l2) {
    ll * l3 = new ll();
    int carry = 0, val = 0;
    while (l1 != NULL || l2 != NULL) {
        val = l1->getVal() + l2->getVal() + carry;
        carry = val / 10;
        val = val % 10;
        l3->insert(val);
        l1 = l1->getNext();
        l2 = l2->getNext();
    }
    while (l1 != NULL) {
        val = l1->getVal() + carry;
        carry = val / 10;
        val = val % 10;
        l3->insert(val);
        l1 = l1->getNext();
    }
    while (l2 != NULL) {
        val = l2->getVal() + carry;
        carry = val / 10;
        val = val % 10;
        l3->insert(val);
        l2 = l2->getNext();
    }
    if (carry != 0) l3->insert(carry);
    return l3;
}

void insert_circle (ll * l) {
    Node * temp = l->kth_to_last (5);
    Node * last = l->kth_to_last (1);
    last->setNext(temp);
}

void detect_and_remove_circle (ll * l) {
    Node * head = l->getFirstEl();
    Node * slow, * fast;
    slow = fast = head;
    slow = slow->getNext();
    fast = fast->getNext()->getNext();
    while (slow != fast) {
        slow = slow->getNext();
        fast = fast->getNext()->getNext();
    }
    slow = slow->getNext();
    int circle_length = 1;
    while (slow != fast) {
        slow = slow->getNext();
        circle_length++;
    }
    slow = fast = head;
    while (circle_length > 1) {
        slow = slow->getNext();
        circle_length--;
    }
    while (slow->getNext() != fast) {
        slow = slow->getNext();
        fast = fast->getNext();
    }
    slow->setNext(NULL);
    head = NULL;
    delete head;
    slow = NULL;
    delete head;
    fast = NULL;
    delete fast;
}

bool isPalindrome(ll *l) {
    ll * temp = new ll();
    Node * head = l->getFirstEl();
    while (head != NULL) {
        temp->insert(head->getVal());
        head = head->getNext();
    }
    l->reverse();
    head = l->getFirstEl();
    Node * head2 = temp->getFirstEl();
    while (head != NULL) {
        if (head->getVal() != head2->getVal()) return false;
        head = head->getNext();
        head2 = head2->getNext();
    }
    return true;
}


int main () {
    ll * l = new ll();
    for (int i = 0; i < 10; i++) l->insert(i + 1);

    l->insert(1);
    l->insert(9);
    l->insert(9);
    l->insert(9);
    l->insert(9);
    l->insert(4);
    l->insert(4);
    l->insert(4);
    l->insert(4);
    l->insert(2);
    l->print();
    cout << l->find(15) << endl;
    cout << l->find(5) << endl;
    l->remove_dups();
    l->del(15);
    l->print();
    cout << endl;
    l->del(1);
    l->print();
    cout << endl;
    del_node(l->kth_to_last(4));
    cout << endl;
    l->print();
    cout << endl;
    l->reverse();
    l->print();
    cout << endl;
    l->partition(6);
    l->print();
    cout << endl;

    cout << "before removing circle." << endl;
    insert_circle (l);
    cout << "after removing circle." << endl;
    detect_and_remove_circle (l);
    l->print();
    cout << endl;

/*
    ll * l1 = new ll();
    l1->insert(7);
    l1->insert(1);
    l1->insert(6);

    ll * l2 = new ll();
    l2->insert(5);
    l2->insert(9);
    l2->insert(2);

    ll * l3 = add(l1->getFirstEl(), l2->getFirstEl());
    l3->print();
    cout << endl;
    */
    
    ll * l4 = new ll();
    l4->insert(1);
    l4->insert(2);
    l4->insert(3);
    l4->insert(2);
    l4->insert(1);
    cout << isPalindrome(l4) << endl;
}