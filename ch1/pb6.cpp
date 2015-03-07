// Rotate a NxN matrix.

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int rotate (int ** matrix, int N) {
    int x, y;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i; j < N - 1 - i; j++) {
            x = matrix[j][N - 1 - i];
            matrix[j][N - 1 - i] = matrix[i][j];
            y = matrix[N - 1 - i][N - 1 - j];
            matrix[N - 1 - i][N - 1 - j] = x;
            x = matrix[N - 1 - j][i];
            matrix[N - 1 - j][i] = y;
            matrix[i][j] = x;
        }
    }
}

int main() {
    srand(time(0));
    int N = 5; // + rand () % 5;
    int ** matrix = new int * [N];
    for (int i = 0; i < N; i++) {
        matrix[i] = new int[N];
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 50 +  1;
            cout << matrix[i][j] << '\t';
        }
        cout << endl;
    }
    rotate (matrix, N);
    cout << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << '\t';
        }
        cout << endl;
    }
}
