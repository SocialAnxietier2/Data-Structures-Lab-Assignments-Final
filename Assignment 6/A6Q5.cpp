#include <iostream>
using namespace std;

int main() {
    const int N = 100;
    int data[N], nextIndex[N];
    int n, c;
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "False";
        return 0;
    }

    cout << "Enter 1 if the list is circular, 0 if not: ";
    cin >> c;

    cout << "Enter " << n << " node values: ";
    for (int i = 0; i < n; i++) cin >> data[i];

    for (int i = 0; i < n - 1; i++) nextIndex[i] = i + 1;
    if (c == 1) nextIndex[n - 1] = 0;
    else nextIndex[n - 1] = -1;

    int head = 0;
    int slow = head, fast = head;
    bool circular = false;

    while (fast != -1 && nextIndex[fast] != -1) {
        slow = nextIndex[slow];
        fast = nextIndex[nextIndex[fast]];
        if (slow == fast) {
            circular = true;
            break;
        }
    }

    if (circular) cout << "True";
    else cout << "False";

    return 0;
}