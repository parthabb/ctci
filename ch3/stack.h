// Stack class .H file

#ifndef __STACK__
#define __STACK__

class stack {
private:
    int m_size;
    int * m_arr;
    int * m_min;
    int m_top;
public:
    stack (int size);
    ~stack ();
    void push (int val);
    int pop ();
    int top ();
    bool isEmpty();
    int min();
};

#endif
