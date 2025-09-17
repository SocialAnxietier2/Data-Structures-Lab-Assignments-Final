#include <iostream>
using namespace std;

int main() {
    const int MAX = 10;
    int r1, c1, r2, c2;
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    cout << "Enter r1 c1: ";
    cin >> r1 >> c1;
    cout << "Enter r2 c2: ";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Invalid sizes. c1 must equal r2.\n";
        return 0;
    }

    cout << "Enter A (" << r1 << "x" << c1 << "):\n";
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> A[i][j];

    cout << "Enter B (" << r2 << "x" << c2 << "):\n";
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> B[i][j];

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            int sum = 0;
            for (int k = 0; k < c1; k++) sum += A[i][k] * B[k][j];
            C[i][j] = sum;
        }
    }

    cout << "Result C (" << r1 << "x" << c2 << "):\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) cout << C[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
