// Set entire row and column to 0 if element is 0;

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int set_zero (int ** matrix, int M, int N) {
    int row[M];
    int col[N];
    for (int i = 0; i < M; i++) row[i] = 1;
    for (int i = 0; i < N; i++) col[i] = 1;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == 0) {
                row[i] = 0;
                col[j] = 0;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        if (row[i] == 0) for (int j = 0; j < N; j++) matrix[i][j] = 0;
    }

    for (int i = 0; i < N; i++) {
        if (col[i] == 0) for (int j = 0; j < M; j++) matrix[j][i] = 0;
    }
}

int main () {
    srand(time(0));
    int N = 5; // + rand () % 5;
    int ** matrix = new int * [N];
    for (int i = 0; i < N; i++) {
        matrix[i] = new int[N];
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 50 +  1;
//            cout << matrix[i][j] << '\t';
        }
//        cout << endl;
    }
    cout << endl;
    matrix[2][4] = 0;
    matrix[1][2] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << '\t';
        }
        cout << endl;
    }
    
    set_zero (matrix, N, N);
    cout << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << '\t';
        }
        cout << endl;
    }
}