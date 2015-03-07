// CPP file for stack.

#include <iostream>
#include "stack.h"

using namespace std;

stack :: stack (int size) {
    m_arr = new int[size];
    for (int i = 0; i < size; i++) m_arr[i] = 0;
    m_size = size;
    m_min = new int[size];
    m_top = -1;
}

stack :: ~stack() {
    delete[] m_arr;
    delete[] m_min;
}

void stack :: push(int val) {
    if ((m_top + 1) > m_size) {
        cout << "Stack is full." << endl;
        return;
    }
    m_top++;
    m_arr[m_top] = val;
    if (m_top == 0) {
        m_min[m_top] = val;
    } else {
        if (val < m_min[m_top - 1]) {
            m_min[m_top] = val;
        } else {
            m_min[m_top] = m_min[m_top - 1];
        }
    }
}

int stack :: pop () {
    if (m_top < 0) {
        cout << "Stack is Empty." << endl;
        return -1;
    }
    int val = m_arr[m_top];
    m_arr[m_top] = 0;
    m_min[m_top] = 0;
    m_top--;
    return val;
}

int stack :: top () {
    if (m_top < 0) {
        cout << "Stack is Empty." << endl;
        return -1;
    }
    return m_arr[m_top];
}

bool stack :: isEmpty () {
    return m_top < 0;
}

int stack :: min() {
    return m_min[m_top];
}
