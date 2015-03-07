// String has all unique chars.

#include <iostream>

using namespace std;

bool all_unique (char str[]) {
    int ch[256], i = 0, val;
    for (int i = 0; i < 256; i++) {
        ch[i] = 0;
    }
    while(str[i] != '\0') {
        val = str[i];
        if (ch[val] != 0) {
            return false;
        }
        ch[val] = 1;
        i++;
    }
    return true;
}

int main() {
    cout << all_unique ("a") << endl;
    cout << all_unique ("aa") << endl;
    cout << all_unique ("ab") << endl;
    cout << all_unique ("abcd") << endl;
    cout << all_unique ("abad") << endl;
}