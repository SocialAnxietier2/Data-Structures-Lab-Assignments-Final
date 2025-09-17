#include <iostream>
using namespace std;

int main() {
    int m;
    cin >> m;

    int cnt[26];
    for (int i = 0; i < 26; i++) {
        cnt[i] = 0;
    }

    char seq[500];

    for (int i = 0; i < m; i++) {
        char ch;
        cin >> ch;
        seq[i] = ch;
        int id = ch - 'a';
        cnt[id] = cnt[id] + 1;

        int ok = 0;
        for (int j = 0; j <= i; j++) {
            int id2 = seq[j] - 'a';
            if (cnt[id2] == 1) {
                cout << seq[j] << "\n";
                ok = 1;
                break;
            }
        }
        if (ok == 0) {
            cout << -1 << "\n";
        }
    }

    return 0;
}
