#include <iostream>
using namespace std;

int main() {
    const int N = 200;
    int q[N];
    int f = 0, r = -1;
    int ch, x;

    do {
        cout << "1 Enqueue\n";
        cout << "2 Dequeue\n";
        cout << "3 isEmpty\n";
        cout << "4 isFull\n";
        cout << "5 Display\n";
        cout << "6 Peek\n";
        cout << "7 Exit\n";
        cin >> ch;

        switch (ch) {
            case 1: {
                cin >> x;
                if (r == N - 1) {
                    cout << "Full\n";
                } else {
                    r = r + 1;
                    q[r] = x;
                    cout << "OK\n";
                }
                break;
            }
            case 2: {
                if (f > r) {
                    cout << "Empty\n";
                } else {
                    cout << q[f] << "\n";
                    f = f + 1;
                }
                break;
            }
            case 3: {
                if (f > r) { cout << "Yes\n"; } 
                else { cout << "No\n"; }
                break;
            }
            case 4: {
                if (r == N - 1) { cout << "Yes\n"; } 
                else { cout << "No\n"; }
                break;
            }
            case 5: {
                if (f > r) {
                    cout << "Empty\n";
                } else {
                    for (int i = f; i <= r; i = i + 1) {
                        cout << q[i] << "\n";
                    }
                }
                break;
            }
            case 6: {
                if (f > r) { cout << "Empty\n"; } 
                else { cout << q[f] << "\n"; }
                break;
            }
            case 7: {
                break;
            }
            default: {
                cout << "invalid\n";
            }
        }
    } 
    while (ch != 7);
    return 0;
}
