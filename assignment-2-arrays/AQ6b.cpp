#include <iostream>
using namespace std;

int main() {
    const int M = 10000;
    int r, c, n, r2, c2, p;
    int rr[M], cc[M], vv[M];
    int i, j, k, x, y, z;

    cin >> r >> c >> n;
    for (i = 0; i < n; i++) {
        cin >> rr[i] >> cc[i] >> vv[i];
    }

    cin >> r2 >> c2 >> p;
    if (r != r2 || c != c2) {
        cout << "Size mismatch\n";
        return 0;
    }

    for (j = 0; j < p; j++) {
        cin >> x >> y >> z;
        int pos = -1;
        for (i = 0; i < n; i++) {
            if (rr[i] == x && cc[i] == y) {
                pos = i;
            }
        }
        if (pos == -1) {
            rr[n] = x; cc[n] = y; vv[n] = z; n++;
        } else {
            vv[pos] = vv[pos] + z;
        }
    }

    k = 0;
    for (i = 0; i < n; i++) {
        if (vv[i] != 0) {
            rr[k] = rr[i]; cc[k] = cc[i]; vv[k] = vv[i]; k++;
        }
    }

    for (i = 0; i < k; i++) {
        cout << rr[i] << "\n";
        cout << cc[i] << "\n";
        cout << vv[i] << "\n";
    }
    return 0;
}
