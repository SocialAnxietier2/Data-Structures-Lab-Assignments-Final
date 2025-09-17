#include <iostream>
using namespace std;

int main() {
    int n; int S[5050];
    cout << "n: "; cin >> n;
    int x = 0;
    cout << "Enter lower triangle (i>=j):\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
            cin >> S[x++];}}

 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int ii = i, jj = j;
            if (ii < jj) { int tmp = ii; ii = jj; jj = tmp; }
            int x = S[ii*(ii+1)/2 + jj];
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
