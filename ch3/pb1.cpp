// Implement 3 stacks from an array.

#include <iostream>

using namespace std;

class stack3 {
private:
    int * m_arr;
    int m_size;
    int m_top[3];
public:
    stack3(int size);
    ~stack3();
    void push(int val, int stack_no);
    int pop (int stack_no);
    int top(int stack_no);
    bool isEmpty(int stack_no);
};

stack3 :: stack3(int size) {
    m_arr = new int[3 * size];
    for (int i = 0; i < 3 * size; i++) m_arr[i] = 0;
    m_size = size;
    for (int i = 0; i < 3; i++) m_top[i] = -1;
}

stack3 :: ~stack3() {
    delete[] m_arr;
}

void stack3 :: push (int val, int stack_no) {
    stack_no--;
    if ((m_top[stack_no] + 1) >= m_size) {
        cout << "Stack is full" << endl;
        return;
    }
    m_top[stack_no]++;
    m_arr[(m_size * stack_no) + m_top[stack_no]] = val;
}

int stack3 :: pop (int stack_no) {
    stack_no--;
    if ((m_top[stack_no] + 1) <= 0) {
        cout << "Stack is empty." << endl;
        return -1;
    }
    int val = m_arr[(m_size * stack_no) + m_top[stack_no]];
    m_arr[(m_size * stack_no) + m_top[stack_no]] = 0;
    m_top[stack_no]--;
    return val;
}

int stack3 :: top (int stack_no) {
    stack_no--;
    if ((m_top[stack_no] + 1) <= 0) {
        cout << "Stack is empty." << endl;
        return -1;
    }
    return m_arr[(m_size * stack_no) + m_top[stack_no]];
}

bool stack3 :: isEmpty(int stack_no) {
    stack_no--;
    return m_top[stack_no] + 1 <= 0;
}


int main() {
    stack3 s3(10);

    cout << s3.isEmpty(1) << endl;
    cout << s3.isEmpty(2) << endl;
    cout << s3.isEmpty(3) << endl;

    cout << s3.top(1) << endl;
    cout << s3.top(2) << endl;
    cout << s3.top(3) << endl;

    for (int i = 0; i < 11; i++) {
        s3.push(3 * i, 1);
        cout << s3.top(1) << '\t';
    }
    cout << endl;
    for (int i = 0; i < 11; i++) {
        s3.push(3 * i + 1, 2);
        cout << s3.top(2) << '\t';
    }
    cout << endl;
    for (int i = 0; i < 11; i++) {
        s3.push(3 * i + 2, 3);
        cout << s3.top(3) << '\t';
    }
    cout << endl;

    cout << s3.isEmpty(1) << endl;
    cout << s3.isEmpty(2) << endl;
    cout << s3.isEmpty(3) << endl;

    for (int i = 0; i < 11; i++) {
        cout << s3.pop(1) << '\t';
    }
    cout << endl;
    for (int i = 0; i < 11; i++) {
        cout << s3.pop(2) << '\t';
    }
    cout << endl;
    for (int i = 0; i < 11; i++) {
        cout << s3.pop(3) << '\t';
    }
    cout << endl;

    cout << s3.isEmpty(1) << endl;
    cout << s3.isEmpty(2) << endl;
    cout << s3.isEmpty(3) << endl;

    cout << s3.top(1) << endl;
    cout << s3.top(2) << endl;
    cout << s3.top(3) << endl;
}