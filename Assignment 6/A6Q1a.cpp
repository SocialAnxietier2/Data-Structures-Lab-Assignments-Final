#include <iostream>
using namespace std;

const int N = 100;
int dataCLL[N], nextCLL[N];
int head = -1;
int freeIndex = 0;

void insertFirst() {
    int x;
    cout << "Enter value to insert at beginning: ";
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
        nextCLL[i] = head;
        nextCLL[p] = i;
        head = i;
    }
}

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

void insertAfter() {
    if (head == -1) {
        cout << "List is empty.\n";
        return;
    }
    int val, x;
    cout << "Enter existing value to insert after: ";
    cin >> val;
    cout << "Enter new value: ";
    cin >> x;
    int p = head;
    bool found = false;
    do {
        if (dataCLL[p] == val) {
            found = true;
            break;
        }
        p = nextCLL[p];
    } while (p != head);
    if (!found) {
        cout << "Value not found.\n";
        return;
    }
    if (freeIndex >= N) return;
    int i = freeIndex++;
    dataCLL[i] = x;
    nextCLL[i] = nextCLL[p];
    nextCLL[p] = i;
}

void insertBefore() {
    if (head == -1) {
        cout << "List is empty.\n";
        return;
    }
    int val, x;
    cout << "Enter existing value to insert before: ";
    cin >> val;
    cout << "Enter new value: ";
    cin >> x;

    int p = head;
    int prev = -1;
    bool found = false;
    do {
        if (dataCLL[p] == val) {
            found = true;
            break;
        }
        prev = p;
        p = nextCLL[p];
    } while (p != head);

    if (!found) {
        cout << "Value not found.\n";
        return;
    }

    if (freeIndex >= N) return;
    int i = freeIndex++;
    dataCLL[i] = x;

    if (p == head) {
        int tail = head;
        while (nextCLL[tail] != head) tail = nextCLL[tail];
        nextCLL[i] = head;
        nextCLL[tail] = i;
        head = i;
    } else {
        nextCLL[prev] = i;
        nextCLL[i] = p;
    }
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
        cout << "\n1 Insert at beginning\n2 Insert at end\n3 Insert after value\n4 Insert before value\n5 Display list\n0 Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        if (ch == 0) break;
        if (ch == 1) insertFirst();
        else if (ch == 2) insertLast();
        else if (ch == 3) insertAfter();
        else if (ch == 4) insertBefore();
        else if (ch == 5) displayCLL();
    }
    return 0;
}