#include <iostream>
using namespace std;

int main() {
    int data[100];
    int nxt[100];
    int head = -1;
    int freeIndex = 0;
    int ch;

    do {
        cout << "1. IB\n2. IE\n3. DB\n4. DE\n5. Search\n6. Display\n7. Exit\n";
        cin >> ch;

        if (ch == 1) {
            int x;
            cin >> x;
            data[freeIndex] = x;
            nxt[freeIndex] = head;
            head = freeIndex;
            freeIndex++;
            cout << "OK\n";
        }
        else if (ch == 2) {
            int x;
            cin >> x;
            data[freeIndex] = x;
            nxt[freeIndex] = -1;
            if (head == -1) {
                head = freeIndex;
            }
            else {
                int p = head;
                while (nxt[p] != -1) {
                    p = nxt[p];
                }
                nxt[p] = freeIndex;
            }
            freeIndex++;
            cout << "OK\n";
        }
        else if (ch == 3) {
            if (head == -1) {
                cout << "Empty\n";
            }
            else {
                cout << data[head] << "\n";
                head = nxt[head];
            }
        }
        else if (ch == 4) {
            if (head == -1) {
                cout << "Empty\n";
            }
            else if (nxt[head] == -1) {
                cout << data[head] << "\n";
                head = -1;
            }
            else {
                int p = head;
                while (nxt[p] != -1 && nxt[nxt[p]] != -1) {
                    p = nxt[p];
                }
                cout << data[nxt[p]] << "\n";
                nxt[p] = -1;
            }
        }
        else if (ch == 5) {
            int k;
            cin >> k;
            int p = head;
            int pos = 1;
            int f = 0;
            while (p != -1) {
                if (data[p] == k) {
                    cout << pos << "\n";
                    f = 1;
                    break;
                }
                p = nxt[p];
                pos++;
            }
            if (f == 0) {
                cout << "NF\n";
            }
        }
        else if (ch == 6) {
            if (head == -1) {
                cout << "Empty\n";
            }
            else {
                int p = head;
                while (p != -1) {
                    cout << data[p] << " ";
                    p = nxt[p];
                }
                cout << "\n";
            }
        }
        else if (ch == 7) {
        }
        else {
            cout << "Invalid\n";
        }
    } while (ch != 7);

    return 0;
}
