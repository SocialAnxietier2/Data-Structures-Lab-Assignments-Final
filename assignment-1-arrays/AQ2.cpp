#include <iostream>
using namespace std;

int main() {
    int a[100];
    int n;
    cout << "Enter size (max 100): ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                for (int k = j; k < n - 1; k++) a[k] = a[k + 1];
                n--;
                j--; // stay on same index to re-check the shifted value
            }
        }
    }

    cout << "Array with unique elements: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
    return 0;
}
