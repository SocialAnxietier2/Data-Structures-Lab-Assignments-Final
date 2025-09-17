#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, out;
    cout << "Enter string (no spaces): ";
    cin >> s;

    out = "";
    for (int i = 0; i < (int)s.size(); i++) {
        char ch = s[i];
        bool v = false;

        if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ||
            ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U') {
            v = true;
        }

        if (!v) {
            out = out + ch;
        }
    }

    cout << "Without vowels: " << out << "\n";
    return 0;
}
