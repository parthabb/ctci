#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> s1, s2;
public:
    void enqueue(int val);
    int dequeue();
    bool empty();
};

void MyQueue :: enqueue (int val) {
    s1.push(val);
}

int MyQueue :: dequeue () {
    while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }
    int temp = s2.top();
    s2.pop();
    while (!s2.empty()) {
        s1.push(s2.top());
        s2.pop();
    }
    return temp;
}

bool MyQueue :: empty() {
    return s1.empty();
}

int main () {
    MyQueue mq;
    cout << mq.empty() << endl;
    for (int i = 0; i < 25; i++) mq.enqueue (i);
    cout << mq.empty() << endl;
    for (int i = 0; i < 25; i++) cout << mq.dequeue () << '\t';
    cout << endl;
    cout << mq.empty() << endl;
}