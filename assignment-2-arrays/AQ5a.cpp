#include <iostream>
using namespace std;

int main() {
    int n; int diag[100];
    cout << "n: "; cin >> n;
    cout << "Enter diagonal elements a[i][i]:\n";
    for (int i = 0; i < n; i++){ 
         cin >> diag[i]; }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = (i == j) ? diag[i] : 0;
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
