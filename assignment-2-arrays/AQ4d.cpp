#include <iostream>
#include <string>
using namespace std;

int main() {
    int m;
    string s[50];

    cout << "How many strings (<=50): ";
    cin >> m;

    for (int i = 0; i < m; i++) {
        cout << "Str " << (i + 1) << " (no spaces): ";
        cin >> s[i];
    }

    for (int pass = 0; pass < m - 1; pass++) {
        for (int j = 0; j < m - 1 - pass; j++) {
            if (s[j] > s[j + 1]) {
                string t = s[j];
                s[j] = s[j + 1];
                s[j + 1] = t;
            }
        }
    }

    cout << "Sorted:\n";
    for (int i = 0; i < m; i++) {
        cout << s[i] << "\n";
    }
    return 0;
}
