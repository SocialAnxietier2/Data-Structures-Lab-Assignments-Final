#include <iostream>
using namespace std;

int main() {
    int a[7] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;
    for (int q = 0; q < n - 1; q++) {
        for (int j = 0; j < n - 1 - q; j++) {
            if (a[j] > a[j + 1]) {
                int t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
            }
        }
    }
    cout << "Sorted: ";
    for (int i = 0; i < n; i++){
    cout << a[i] << " ";
    cout << "\n";
    }
    return 0;
}
