#include <iostream>
using namespace std;

int main() {
    int n; int L[5050]; 
    cout << "n: "; cin >> n;
    int d = 0;
    cout << "Enter lower triangle (row-wise i>=j):\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
            cin >> L[d++];
        }
    }
  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = (i >= j) ? L[i*(i+1)/2 + j] : 0;
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
