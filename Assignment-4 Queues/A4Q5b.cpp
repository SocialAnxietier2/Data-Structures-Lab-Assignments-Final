#include <iostream>
using namespace std;

int main() {
    const int N = 500;
    int q[N];
    int f = 0, r = 0, n = 0;
    int ch, x;

    do {
        cout << "1 Push\n";
        cout << "2 Pop\n";
        cout << "3 Top\n";
        cout << "4 Display\n";
        cout << "5 Exit\n";
        cin >> ch;

        switch (ch) {
            case 1: {
                cin >> x;
                if (n == N) {
                    cout << "Full\n";
                } else {
                    q[r] = x; r = (r + 1) % N; n = n + 1;
                    for (int i = 0; i < n - 1; i = i + 1) {
                        int y = q[f]; f = (f + 1) % N; n = n - 1;
                        q[r] = y; r = (r + 1) % N; n = n + 1;
                    }
                    cout << "OK\n";
                }
                break;
            }
            case 2: {
                if (n == 0) {
                    cout << "Empty\n";
                } else {
                    int v = q[f]; f = (f + 1) % N; n = n - 1;
                    cout << v << "\n";
                }
                break;
            }
            case 3: {
                if (n == 0) {
                    cout << "Empty\n";
                } else {
                    cout << q[f] << "\n";
                }
                break;
            }
            case 4: {
                if (n == 0) {
                    cout << "Empty\n";
                } else {
                    for (int i = 0; i < n; i = i + 1) {
                        int idx = (f + i) % N;
                        cout << q[idx] << "\n";
                    }
                }
                break;
            }
            case 5: {
                break;
            }
            default: {
                cout << "Bad\n";
            }
        }
    } while (ch != 5);

    return 0;
}
