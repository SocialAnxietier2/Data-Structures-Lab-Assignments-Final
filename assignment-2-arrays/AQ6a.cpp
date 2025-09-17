#include <iostream>
using namespace std;

int main() {
    const int MAX = 3000;
    int r, c, nz;
    int R[MAX], C[MAX], V[MAX];
    int TR[MAX], TC[MAX], TV[MAX];

    cin >> r >> c >> nz;
    for (int i = 0; i < nz; i++) {
        cin >> R[i] >> C[i] >> V[i];
    }

    for (int i = 0; i < nz; i++) {
        TR[i] = C[i];
        TC[i] = R[i];
        TV[i] = V[i];
    }

    for (int p = 0; p < nz - 1; p++) {
        for (int q = 0; q < nz - 1 - p; q++) {
            if (TR[q] > TR[q + 1] || (TR[q] == TR[q + 1] && TC[q] > TC[q + 1])) {
                int t;
                t = TR[q]; TR[q] = TR[q + 1]; TR[q + 1] = t;
                t = TC[q]; TC[q] = TC[q + 1]; TC[q + 1] = t;
                t = TV[q]; TV[q] = TV[q + 1]; TV[q + 1] = t;
            }
        }
    }

    for (int i = 0; i < nz; i++) {
        cout << TR[i] << " " << TC[i] << " " << TV[i] << "\n";
    }
    return 0;
}
