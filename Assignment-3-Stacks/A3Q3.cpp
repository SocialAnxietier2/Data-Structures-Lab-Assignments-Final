#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    char st[1000];
    int top = -1;
    bool ok = true;

    for (int i = 0; i < (int)s.size(); i++) {
        char ch = s[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            top = top + 1;
            st[top] = ch;
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (top == -1) {
                ok = false;
            } else {
                char t = st[top];
                top = top - 1;
                if (!((t == '(' && ch == ')') || (t == '[' && ch == ']') || (t == '{' && ch == '}'))) {
                    ok = false;
                }
            }
        } else {
        }
    }

    if (ok && top == -1) {
        cout << "Balanced\n";
    } else {
        cout << "Not Balanced\n";
    }
    return 0;
}
