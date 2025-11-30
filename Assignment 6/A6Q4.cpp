#include <iostream>
using namespace std;
int main() {
    const int N = 100;
    char dataDLL[N];
    int nextDLL[N], prevDLL[N];
    int head = -1, tail = -1;

    string s;
    cin >> s;
    int n = s.length();

    if (n == 0) {
        cout << "True";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        dataDLL[i] = s[i];
        nextDLL[i] = (i == n - 1) ? -1 : i + 1;
        prevDLL[i] = (i == 0) ? -1 : i - 1;
    }

    head = 0;
    tail = n - 1;

    int left = head, right = tail;
    bool ok = true;

    while (left < right) {
        if (dataDLL[left] != dataDLL[right]) {
            ok = false;
            break;
        }
        left = nextDLL[left];
        right = prevDLL[right];
    }

    if (ok) cout << "True";
    else cout << "False";

    return 0;
}