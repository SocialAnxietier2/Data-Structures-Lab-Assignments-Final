#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Enter string (no spaces): ";
    cin >> s;

    int i = 0;
    int j = (int)s.size() - 1;

    while (i < j) {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
        i = i + 1;
        j = j - 1;
    }

    cout << "Reversed: " << s << "\n";
    return 0;
}
