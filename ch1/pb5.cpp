// Basic string compression.

#include<iostream>

using namespace std;

char * compress (char str[]) {
    int len = 0;
    while(str[len] != '\0') len++;

    char * cs = new char[2 * len];
    int i, j, count;
    i = 0;
    j = 0;
    char c = str[i];
    i++;
    count = 1;
    while(str[i] != '\0') {
        if (str[i] == c) {
            count++;
        } else {
            cs[j] = c;
            j++;
            cs[j] = '0' + count;
            j++;
            c = str[i];
            count = 1;
        }
        i++;
    }
    cs[j] = c;
    j++;
    cs[j] = '0' + count;
    j++;
    cs[j] = '\0';
    if (j > len) return str; 
    return cs;
}

int main() {
    char str[] = "aabcccccaaa";
    cout << compress (str) << endl;
    char str2[] = "abcd";
    cout << compress (str2) << endl;
}