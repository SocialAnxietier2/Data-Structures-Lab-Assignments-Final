//Naman Bhatnagar[1024030165]
#include <iostream>
using namespace std;

int main() {
    const int N = 100;
    int st[N];
    int top = -1;
    int ch, x;

    do {
        cout << "1 Push\n";
       cout << "2 Pop\n";
        cout << "3 isEmpty\n";
        cout << "4 isFull\n";
        cout << "5 Display\n";
        cout << "6 Peek\n";
        cout << "7 Exit\n";
        cin >> ch;

        switch (ch) {
            case 1: {
                cin >> x;
                if (top == N - 1) {
                    cout << "Full\n";
                } else {
                    top = top + 1;
                    st[top] = x;
                    cout << "OK\n";
                }
                break;
            }
            case 2: {
                if (top == -1) {
                    cout << "Empty\n";
                } else {
                    cout << st[top] << "\n";
                    top = top - 1;
                }
                break;
            }
            case 3: {
                if (top == -1) {
                    cout << "Yes\n";
                } else {
                    cout << "No\n";
                }
                break;
            }
            case 4: {
                if (top == N - 1) {
                    cout << "Yes\n";
                } else {
                    cout << "No\n";
                }
                break;
            }
            case 5: {
                if (top == -1) {
                    cout << "Empty\n";
                } else {
                    for (int i = top; i >= 0; i--) {
                        cout << st[i] << "\n";
                    }
                }
                break;
            }
            case 6: {
                if (top == -1) {
                    cout << "Empty\n";
                } else {
                    cout << st[top] << "\n";
                }
                break;
            }
            case 7: {
                break;
            }
            default: {
                cout << "Bad\n";
            }
        }
    } while (ch != 7);

    return 0;
}
