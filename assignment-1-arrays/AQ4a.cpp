#include <iostream>
using namespace std;

int main() {
    int a[100], n;
    cout << "Enter size (max 100): ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    int i = 0, j = n - 1, temp;
    while (i < j) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }

    cout << "Reversed array: ";
    for (int k = 0; k < n; k++) cout << a[k] << " ";
    cout << "\n";
    return 0;
}
