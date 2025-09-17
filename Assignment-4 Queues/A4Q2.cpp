#include <iostream>
using namespace std;

int main() {
    const int N = 200;
    int q[N];
    int f = 0, r = 0, cnt = 0;
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
                if (cnt == N) {
                    cout << "Full\n";
                } else {
                    q[r] = x;
                    r = (r + 1) % N;
                    cnt = cnt + 1;
                    cout << "OK\n";
                }
                break;
            }
            case 2: {
                if (cnt == 0) {
                    cout << "Empty\n";
                } else {
                    cout << q[f] << "\n";
                    f = (f + 1) % N;
                    cnt = cnt - 1;
                }
                break;
            }
            case 3: {
                if (cnt == 0) { 
                    cout << "Yes\n"; } 
                else { 
                    cout << "No\n"; }
                break;
            }
            case 4: {
                if (cnt == N) { 
                    cout << "Yes\n";
                 }
                 else {
                     cout << "No\n"; 
                    }
                break;
            }
            case 5: {
                if (cnt == 0) {
                    cout << "Empty\n";
                } else {
                    for (int i = 0; i < cnt; i = i + 1) {
                        int idx = (f + i) % N;
                        cout << q[idx] << "\n";
                    }
                }
                break;
            }
            case 6: {
                if (cnt == 0) {
                     cout << "Empty\n"; } 
                else { 
                    cout << q[f] << "\n"; }
                break;
            }
            case 7: {
                break;
            }
            default: {
                cout << "Invalid \n";
            }
        }
    } while (ch != 7);

    return 0;
}
