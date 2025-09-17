#include <iostream>
using namespace std;

int main() {
    int n, a[200];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int inv = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                inv = inv + 1;
            }
        }
    }
    cout << inv << "\n";
    return 0;
}
