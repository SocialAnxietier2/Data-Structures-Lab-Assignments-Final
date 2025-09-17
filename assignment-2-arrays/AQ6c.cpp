#include <iostream>
using namespace std;

int main() {
    const int M = 10000;
    int r1, c1, n, r2, c2, p;
    int r[M], c[M], v[M];
    int rb[M], cb[M], vb[M];
    int rd[M], cd[M], vd[M], t = 0;
    int i, j, pos;

    cin >> r1 >> c1 >> n;
    for (i = 0; i < n; i++) {
        cin >> r[i] >> c[i] >> v[i];
    }

    cin >> r2 >> c2 >> p;
    for (i = 0; i < p; i++) {
        cin >> rb[i] >> cb[i] >> vb[i];
    }

    if (c1 != r2) {
        cout << "Size mismatch\n";
        return 0;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < p; j++) {
            if (c[i] == rb[j]) {
                int rr = r[i];
                int cc = cb[j];
                int val = v[i] * vb[j];
                pos = -1;
                for (int q = 0; q < t; q++) {
                    if (rd[q] == rr && cd[q] == cc) {
                        pos = q;
                    }
                }
                if (pos == -1) {
                    rd[t] = rr; cd[t] = cc; vd[t] = val; t++;
                } else {
                    vd[pos] = vd[pos] + val;
                }
            }
        }
    }

    int k = 0;
    for (i = 0; i < t; i++) {
        if (vd[i] != 0) {
            rd[k] = rd[i]; cd[k] = cd[i]; vd[k] = vd[i]; k++;
        }
    }

    for (i = 0; i < k; i++) {
        cout << rd[i] << "\n";
        cout << cd[i] << "\n";
        cout << vd[i] << "\n";
    }
    return 0;
}
