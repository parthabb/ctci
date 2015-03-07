#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class SetOfStack {
private:
    vector<stack<int> *> m_stack;
    const static int m_max_size = 20;
    int m_curr_index;
public:
    SetOfStack ();
    void push (int val);
    int pop ();
    int popAt (int index);
    ~SetOfStack();
};

SetOfStack :: SetOfStack () {
    m_curr_index = 0;
    m_stack.push_back(new stack<int>());
}

void SetOfStack :: push(int val) {
    if (m_stack.empty()) {
        m_stack.push_back(new stack<int>());
        m_curr_index++;
    }
    if (m_stack[m_curr_index]->size() > m_max_size) {
        m_stack.push_back(new stack<int>());
        m_curr_index++;
    }
    m_stack[m_curr_index]->push(val);
}

int SetOfStack :: pop () {
    if (m_curr_index < 0) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    if (m_stack[m_curr_index]->empty()) {
        stack<int> * temp = m_stack[m_curr_index];
        delete temp;
        m_stack.pop_back();
        m_curr_index--;
        return pop();
    }
    int top = m_stack[m_curr_index]->top();
    m_stack[m_curr_index]->pop();
    return top;
}

int SetOfStack :: popAt(int index) {
    if (index > m_curr_index) {
        cout << "Index out of bounds" << endl;
        return -1;
    }
    int temp = m_stack[index]->top();
    m_stack[index]->pop();
    if (m_stack[index]->empty()) {
        stack <int> * temp = m_stack[index];
        delete temp;
        m_stack.erase(m_stack.begin() + index);
        m_curr_index--;
    }
    return temp;
}

SetOfStack :: ~SetOfStack () {
    for (int i = m_stack.size() - 1; i >= 0; i--) {
        stack<int> * temp = m_stack[i];
        delete temp;
        m_stack.pop_back();
    }
}

int main() {
    SetOfStack sos;
    for (int i = 0; i < 50; i++) sos.push(i);
    for (int i = 0; i < 50; i++) cout << sos.pop() << '\t';
    cout << endl;
    cout << sos.pop();
    cout << endl;
    for (int i = 0; i < 50; i++) sos.push(i);
    cout << sos.popAt(10) << endl;
    for (int i = 0; i < 20; i++) cout << sos.popAt(1) << '\t';
    cout << endl;
    cout << endl;
    for (int i = 0; i < 50; i++) cout << sos.pop() << '\t';
    cout << endl;
    cout << sos.pop();
    cout << endl;
}

