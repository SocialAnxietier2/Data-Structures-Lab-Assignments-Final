#include <iostream>
using namespace std;

int main() {
    const int MAX = 10;
    int r, c, A[MAX][MAX];
    cout << "Enter rows and cols: ";
    cin >> r >> c;

    cout << "Enter matrix (" << r << "x" << c << "):\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> A[i][j];

    cout << "Row sums:\n";
    for (int i = 0; i < r; i++) {
        int s = 0;
        for (int j = 0; j < c; j++) s += A[i][j];
        cout << "Row " << i + 1 << ": " << s << "\n";
    }

    cout << "Column sums:\n";
    for (int j = 0; j < c; j++) {
        int s = 0;
        for (int i = 0; i < r; i++) s += A[i][j];
        cout << "Col " << j + 1 << ": " << s << "\n";
    }
    return 0;
}
