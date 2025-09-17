#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    char st[1000];
    int top = -1;
    string out = "";

    for (int i = 0; i < (int)s.size(); i++) {
        char ch = s[i];
        if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            out = out + ch;
        } else if (ch == '(') {
            top = top + 1;
            st[top] = ch;
        } else if (ch == ')') {
            while (top != -1 && st[top] != '(') {
                out = out + st[top];
                top = top - 1;
            }
            if (top != -1 && st[top] == '(') {
                top = top - 1;
            }
        } else {
            int p;
            if (ch == '+' || ch == '-') {
                p = 1;
            } else if (ch == '*' || ch == '/') {
                p = 2;
            } else if (ch == '^') {
                p = 3;
            } else {
                p = 0;
            }

            while (top != -1) {
                char op = st[top];
                int q;
                if (op == '+' || op == '-') {
                    q = 1;
                } else if (op == '*' || op == '/') {
                    q = 2;
                } else if (op == '^') {
                    q = 3;
                } else {
                    q = 0;
                }
                if (op == '(') {
                    break;
                }
                if (q >= p) {
                    out = out + op;
                    top = top - 1;
                } else {
                    break;
                }
            }
            top = top + 1;
            st[top] = ch;}
    }

    while (top != -1) {
        if (st[top] != '(') {
            out = out + st[top];
        }
        top = top - 1;
    }
    cout << out << "\n";
    return 0;
}

