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

    int slow = head;
    int fast = head;

    while (fast != -1 && nxt[fast] != -1) {
        slow = nxt[slow];
        fast = nxt[nxt[fast]];
    }

    if (slow != -1) {
        cout << data[slow] << "\n";
    }

    return 0;
}
