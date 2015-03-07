// replace all spaces with %20

#include <iostream>

using namespace std;

void replace (char str[], int tl) {
    int len = 0;
    while (str[len] != '\0') len++;

    len--;
    tl--;
    while(len >= 0) {
        if (str[tl] == ' ') {
            str[len] = '0';
            len--;
            str[len] = '2';
            len--;
            str[len] = '%';
        } else {
            str[len] = str[tl];
        }
        tl--;
        len--;
    }
}

int main() {
    char str[] = "Mr John Smith    ";
    cout << str << endl;
    replace(str, 13);
    cout << str << endl;
}