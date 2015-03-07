// Linked list.

#ifndef __LL__
#define __LL__

class ll {
private:
    Node * m_head;
public:
    ll();
    ~ll();
    void insert(int el);
    void del (int el);
    bool find(int el);
    void print();
    void remove_dups();
    Node * kth_to_last(int el);
    void reverse();
    void partition(int val);
    Node * getFirstEl();
};

#endif
