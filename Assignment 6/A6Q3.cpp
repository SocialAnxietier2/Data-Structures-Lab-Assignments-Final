#include <iostream>
using namespace std;

const int N = 100;

int dataDLL[N], nextDLL[N], prevDLL[N];
int headDLL = -1, tailDLL = -1, freeDLL = 0;

int dataCLL[N], nextCLL[N];
int headCLL = -1, freeCLL = 0;

void insertDLLLast() {
    int x;
    cout << "Enter value to insert in DLL: ";
    cin >> x;
    if (freeDLL >= N) return;
    int i = freeDLL++;
    dataDLL[i] = x;
    nextDLL[i] = -1;
    prevDLL[i] = -1;
    if (headDLL == -1) {
        headDLL = i;
        tailDLL = i;
    } else {
        nextDLL[tailDLL] = i;
        prevDLL[i] = tailDLL;
        tailDLL = i;
    }
}

void sizeDLL() {
    int c = 0;
    int p = headDLL;
    while (p != -1) {
        c++;
        p = nextDLL[p];
    }
    cout << "Size of DLL: " << c << "\n";
}

void insertCLLLast() {
    int x;
    cout << "Enter value to insert in CLL: ";
    cin >> x;
    if (freeCLL >= N) return;
    int i = freeCLL++;
    dataCLL[i] = x;
    if (headCLL == -1) {
        headCLL = i;
        nextCLL[i] = i;
    } else {
        int p = headCLL;
        while (nextCLL[p] != headCLL) p = nextCLL[p];
        nextCLL[p] = i;
        nextCLL[i] = headCLL;
    }
}

void sizeCLL() {
    if (headCLL == -1) {
        cout << "Size of CLL: 0\n";
        return;
    }
    int c = 0;
    int p = headCLL;
    do {
        c++;
        p = nextCLL[p];
    } while (p != headCLL);
    cout << "Size of CLL: " << c << "\n";
}

int main() {
    int ch;
    while (true) {
        cout << "\n1 Insert DLL node\n2 Size of DLL\n3 Insert CLL node\n4 Size of CLL\n0 Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        if (ch == 0) break;
        if (ch == 1) insertDLLLast();
        else if (ch == 2) sizeDLL();
        else if (ch == 3) insertCLLLast();
        else if (ch == 4) sizeCLL();
    }
    return 0;
}