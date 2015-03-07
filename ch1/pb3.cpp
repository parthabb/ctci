// strings are permutaions of each other.

#include <iostream>

using namespace std;

bool permutations (char str1[], char str2[]) {
    int len1 = 0, len2 = 0;
    while (str1[len1] != '\0') len1++;
    while (str2[len2] != '\0') len2++;
    if (len1 != len2) return false;

    int ch[256];
    for (int i = 0; i < 256; i++) ch[i] = 0;

    for (int i = 0; i < len1; i++) ch[str1[i]] += 1;

    for (int i = 0; i < len2; i++) ch[str2[i]] -= 1;

    for (int i = 0; i < 256; i++) {
        if (ch[i] != 0) return false;
    }
    return true;
}

int main() {
    cout << permutations ("a", "a") << endl;
    cout << permutations ("ab", "ba") << endl;
    cout << permutations ("123456", "135246") << endl;
    cout << permutations ("hello world!!", "eoo lll!hdrw!") << endl;
    cout << permutations ("abcd", "a") << endl;
    cout << permutations ("d", "a") << endl;
}