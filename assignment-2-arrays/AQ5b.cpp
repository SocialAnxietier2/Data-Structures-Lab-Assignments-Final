#include <iostream>
using namespace std;

int main() {
    int n; int t[300];
    cout << "n: "; cin >> n;
    
    for (int i = 0; i < 3*n-2; i++) {
        t[i] = 0;
    }

    cout << "Enter sub-diagonal (n-1 vals): ";
    for (int i = 1; i < n; i++){
     cin >> t[i-1];
    cout << "Enter main diagonal (n vals): ";}


    for (int i = 0; i < n; i++) {
        cin >> t[(n-1)+i];
    cout << "Enter super-diagonal (n-1 vals): ";
}

    for (int i = 0; i < n-1; i++) {
        cin >> t[(2*n-1)+i];}

   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = 0;
            if (i == j) x = t[(n-1)+i];
            else if (i == j+1) x = t[i-1];
            else if (j == i+1) x = t[(2*n-1)+i];
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
