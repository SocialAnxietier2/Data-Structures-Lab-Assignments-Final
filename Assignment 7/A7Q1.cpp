#include <iostream>
using namespace std;

int a[50], n;
void input() {
    cout << "How many numbers: ";
    cin >> n;
    cout << "Enter numbers:\n";
    for (int i = 0; i < n; i++) cin >> a[i];
}

void show() {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
}

void selectionSort() {
    for (int i = 0; i < n - 1; i++) {
        int p = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[p]) p = j;
        int t = a[i];
        a[i] = a[p];
        a[p] = t;
    }
}

void insertionSort() {
    for (int i = 1; i < n; i++) {
        int k = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > k) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = k;
    }
}

void bubbleSort() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
            int t = a[j];
            a[j] = a[j + 1];
             a[j + 1] = t;
        }
        }
    }
}

int main() {
    int ch;
    while (true) {
        cout << "\n1.Input\n2.Show\n3.Selection Sort\n4.Insertion Sort\n5.Bubble Sort\n6.Exit\nChoose: ";
        cin >> ch;
        if (ch == 1) input();
        else if (ch == 2) show();
        else if (ch == 3) { selectionSort(); show(); }
        else if (ch == 4) { insertionSort(); show(); }
        else if (ch == 5) { bubbleSort(); show(); }
        else if (ch == 6) break;
    }
}