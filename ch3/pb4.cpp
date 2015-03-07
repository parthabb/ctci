#include <iostream>
#include <stack>

using namespace std;

void move (int n, stack<int>& source, stack<int>& destination, stack<int>& buffer) {
    if (n < 1) return;
    move (n - 1, source, buffer, destination);
    destination.push(source.top());
    source.pop();
    move (n - 1, buffer, destination, source);
}

int main () {
    stack<int> s1, s2, s3;
    for (int i = 10; i > 0; i--) s1.push(i);
    move(10, s1, s2, s3);
    if (!s1.empty()) {
      for (int i = 0; i < 10; i++) {
          cout << s1.top() << '\t';
          s1.pop();
      }
    cout << 1 << endl;
    }
    if (!s2.empty()) {
      for (int i = 0; i < 10; i++) {
          cout << s2.top() << '\t';
          s2.pop();
      }
    cout << 2 << endl;
    }
    if (!s3.empty()) {
      for (int i = 0; i < 10; i++) {
          cout << s3.top() << '\t';
          s3.pop();
      }
    cout << 3 << endl;
    }
}