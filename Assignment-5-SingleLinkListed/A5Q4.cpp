#include <iostream>
using namespace std;

int main() {
    int data[100];
    int nxt[100];
    int head = -1;
    int freeIndex = 0;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        data[freeIndex] = x;
        nxt[freeIndex] = -1;
        if (head == -1) {
            head = freeIndex;
        } else {
            int p = head;
            while (nxt[p] != -1) {
                p = nxt[p];
            }
            nxt[p] = freeIndex;
        }
        freeIndex++;
    }

    int prev = -1;
    int cur = head;

    while (cur != -1) {
        int nxtNode = nxt[cur];
        nxt[cur] = prev;
        prev = cur;
        cur = nxtNode;
    }
    head = prev;

    int p = head;
    while (p != -1) {
        cout << data[p];
        if (nxt[p] != -1) {
            cout << "->";
        }
        p = nxt[p];
    }
    cout << "\n";

    return 0;
}
