#include <iostream>
using namespace std;

int main() {
    int n;
    int a[1000];
    cin >> n;
    for (int i = 0; i < n; i = i + 1) {
        cin >> a[i];
    }
    for (int i = 0; i < n / 2; i = i + 1) {
        cout << a[i] << " " << a[i + n / 2] << " ";
    }
    cout << "\n";
    return 0;
}
