#include <iostream>
using namespace std;

int main() {
    int n, key;
    int a[100];
    cout << "Enter size (max 100): ";
    cin >> n;
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
    cin >> a[i]; 
}

    cout << "Enter key to search: ";
    cin >> key;

    int low = 0, high = n - 1, pos = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == key) {
             pos = mid; 
             break; }
        else if (a[mid] < key) {
        low = mid + 1; }
        else 
        {high = mid - 1;}
    }

    if (pos == -1) cout << "Not found\n";
    else cout << "Found at index: " << pos << "\n";
    return 0;
}
