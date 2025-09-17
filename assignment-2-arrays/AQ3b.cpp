#include <iostream>
using namespace std;

int main() {
    int n;
    int a[1000];

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter " << (n - 1) << " sorted numbers (from 1.."<< n <<") with one missing:\n";
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];}

    int low = 0, high = n - 2;
    int ans = n;               
    while (low <= high) {
        int mid = (low + high) / 2;
        int expected = mid + 1;        
        if (a[mid] == expected) {
            low = mid + 1;             
        } else {
            ans = expected;            
            high = mid - 1;            
        }
    }

    cout << "Missing number = " << ans << "\n";
    return 0;
}
