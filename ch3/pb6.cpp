#include<iostream>
#include<cstdlib>
#include<ctime>
#include<stack>

using namespace std;

void sort (stack<int>& s) {
    stack<int> temp;
    int var = -1;
    int size = s.size();
    temp.push(s.top());
    s.pop();
    while (!s.empty()) {
        var = s.top();
        s.pop();
        while(!temp.empty() && temp.top() < var) {
            s.push(temp.top());
            temp.pop();
        }
        temp.push(var);
    }
    while(!temp.empty()) {
        s.push(temp.top());
        temp.pop();
    }
}

int main () {
    stack<int> s;
    srand(time(0));
    int temp;
    for (int i = 0; i < 15; i++) {
        temp = rand() % 100 + 1;
        cout << temp << '\t';
        s.push(temp);
    }
    sort(s);
    cout << endl;
    for (int i = 0; i < 15; i++) {
        cout << s.top() << '\t';
        s.pop();
    }
    cout << endl;
}