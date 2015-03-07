#include <iostream>
#include "stack.h"

using namespace std;

int main () {
    cout << "begin" << endl;
    stack s (10);
    cout << s.isEmpty() << endl;
    cout << s.top() << endl;
    for (int i = 10; i > 0; i--) {
        s.push(i);
        cout << s.top() << endl;
        cout << s.min() << endl;
    }
    cout << s.isEmpty() << endl;
    for (int i = 10; i > 0; i--) {
        cout << s.pop() << endl;
        cout << s.top() << endl;
        cout << s.min() << endl;
    }
    cout << s.isEmpty() << endl;
}