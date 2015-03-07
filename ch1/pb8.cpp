// is rotated string.

#include <iostream>

using namespace std;

bool is_rotation (char * str1, char * str2) {
    int len1 = 0, len2 = 0;
    while (str1[len1] != '\0') len1++;
    while (str2[len2] != '\0') len2++;

    if (len1 != len2) return false;

    int i = 0, j, k;
    bool b = false;
    while (str1[i] != '\0') {
        j = 0;
        k = i;
        i++;
        while(str2[j] != '\0') {
            if (str1[k] == str2[j]) {
                b = true;
                j++;
                k++;
                if (str1[k] == '\0') k = 0;
            } else {
                b = false;
                break;
            }
        }
        if (b == true) break;
    }
    return b;
}



int main () {
    cout << is_rotation ("a", "a") << endl;
    cout << is_rotation ("aa", "aa") << endl;
    cout << is_rotation ("ab", "ba") << endl;
    cout << is_rotation ("abcd", "dcba") << endl;
    cout << is_rotation ("abcd", "cdab") << endl;
    cout << is_rotation ("abcdefg", "cdab") << endl;
}