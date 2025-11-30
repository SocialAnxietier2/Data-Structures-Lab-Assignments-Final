#include <iostream>
using namespace std;

const int N = 100;
int dataCLL[N], nextCLL[N];
int head = -1;
int freeIndex = 0;

void insertLast() {
    int x;
    cout << "Enter value to insert at end: ";
    cin >> x;
    if (freeIndex >= N) return;
    int i = freeIndex++;
    dataCLL[i] = x;
    if (head == -1) {
        head = i;
        nextCLL[i] = i;
    } else {
        int p = head;
        while (nextCLL[p] != head) p = nextCLL[p];
        nextCLL[p] = i;
        nextCLL[i] = head;
    }
}

void searchValue() {
    if (head == -1) {
        cout << "List is empty.\n";
        return;
    }
    int x;
    cout << "Enter value to search: ";
    cin >> x;

    int p = head;
    bool found = false;
    do {
        if (dataCLL[p] == x) {
            found = true;
            break;
        }
        p = nextCLL[p];
    } while (p != head);

    if (found) cout << "Value found.\n";
    else cout << "Value not found.\n";
}

void displayCLL() {
    if (head == -1) {
        cout << "List is empty.\n";
        return;
    }
    cout << "List: ";
    int p = head;
    do {
        cout << dataCLL[p] << " ";
        p = nextCLL[p];
    } while (p != head);
    cout << "\n";
}

int main() {
    int ch;
    while (true) {
        cout << "\n1 Insert at end\n2 Search value\n3 Display list\n0 Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        if (ch == 0) break;
        if (ch == 1) insertLast();
        else if (ch == 2) searchValue();
        else if (ch == 3) displayCLL();
    }
    return 0;
}