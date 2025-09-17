#include <iostream>
using namespace std;

int main() {
    int n, x, sum = 0, total;
    cout << "Enter n: ";
    cin >> n;

    total = n * (n + 1) / 2;

    cout << "Enter " << (n - 1) << " numbers (from 1.."<< n <<"): ";
    for (int i = 0; i < n - 1; i++) {
        cin >> x;
        sum += x;
    }

    cout << "Missing number = " << (total - sum) << "\n";
    return 0;
}
