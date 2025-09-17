#include <iostream>
using namespace std;

int main() {
    int n; int U[5050];
    cout << "n: "; cin >> n;
    int x = 0;
    cout << "Enter upper triangle (column-wise i<=j):\n";
    for (int j = 0; j < n; j++)
        for (int i = 0; i <= j; i++)
            cin >> U[x++];


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = (i <= j) ? U[j*(j+1)/2 + i] : 0;
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
