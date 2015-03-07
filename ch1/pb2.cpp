// Reverse a null terminated string.

#include <iostream>

using namespace std;

void reverse (char str[]) {
    int len = 0;
    while (str[len] != '\0') len++;
    int i, j;
    i = 0;
    j = len - 1;
    char temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int main () {
    char str1[] = "a";
    reverse(str1);
    cout << str1 << endl;
    char str2[] = "aa";
    reverse(str2);
    cout << str2 << endl;
    char str3[] = "ab";
    reverse(str3);
    cout << str3 << endl;
    char str4[] = "abcd";
    reverse(str4);
    cout << str4 << endl;
    char str5[] = "abba";
    reverse(str5);
    cout << str5 << endl;
}