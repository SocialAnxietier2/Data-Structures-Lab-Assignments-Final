#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = (int)s.size();
    char st[1000];
    int top = -1;

    for (int i = 0; i < n; i++) {
        top = top + 1;
        st[top] = s[i];
    }

    string out = "";
    for (int i = 0; i < n; i++) {
        out = out + st[top];
        top = top - 1;
    }

    cout << out << "\n";
    return 0;
}
