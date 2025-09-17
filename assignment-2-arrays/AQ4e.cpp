#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter a character: ";
    cin >> ch;

    if (ch >= 'A' && ch <= 'Z') {
        ch = char(ch + ('a' - 'A'));
    }

    cout << "Lowercase: " << ch << "\n";
    return 0;
}
