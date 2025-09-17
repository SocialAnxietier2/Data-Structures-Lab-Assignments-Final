#include <iostream>
using namespace std;

int main() {
    int n, a[500];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int distinct = 0;
    for (int i = 0; i < n; i++) {
        bool seen = false;
        for (int j = 0; j < i; j++) {
            if (a[j] == a[i]) {
                seen = true;
            }
        }
        if (!seen) {
            distinct = distinct + 1;
        }
    }
    cout << distinct << "\n";
    return 0;
}
