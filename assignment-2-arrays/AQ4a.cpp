#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2, res;

    cout << "First string (no spaces): ";
    cin >> s1;
    cout << "Second string (no spaces): ";
    cin >> s2;

    res = s1 + s2;

    cout << "Concatenated: " << res << "\n";
    return 0;
}
