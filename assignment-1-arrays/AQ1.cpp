//Naman Bhatnagar[1024030165]

#include <iostream>
using namespace std;

int main() {
    int arr[100];
    int n = 0; // current number of elements
    int choice;

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

            case 1: {
                cout << "Enter size (0 to 100): ";
                cin >> n;
                if (n < 0 || n > 100) {
                    cout << "Invalid size. Setting size to 0.\n";
                    n = 0;
                } else {
                    cout << "Enter " << n << " elements: ";
                    for (int i = 0; i < n; i++) cin >> arr[i];
                }
                break;
            }

            case 2: {
                if (n == 0) cout << "Array is empty.\n";
                else {
                    cout << "Array: ";
                    for (int i = 0; i < n; i++) cout << arr[i] << " ";
                    cout << "\n";
                }
                break;
            }

            case 3: {
                if (n == 100) {
                    cout << "Array full. Cannot insert.\n";
                } else {
                    int pos, val;
                    cout << "Enter position to insert (1 to " << (n + 1) << "): ";
                    cin >> pos;
                    cout << "Enter value: ";
                    cin >> val;

                    if (pos < 1 || pos > n + 1) {
                        cout << "Invalid position.\n";
                    } else {
                        // shift right from end to pos-1
                        for (int i = n; i >= pos; i--) {
                            arr[i] = arr[i - 1];
                        }
                        arr[pos - 1] = val;
                        n++;
                        cout << "Inserted.\n";
                    }
                }
                break;
            }

            case 4: {
                if (n == 0) {
                    cout << "Array empty. Nothing to delete.\n";
                } else {
                    int pos;
                    cout << "Enter position to delete (1 to " << n << "): ";
                    cin >> pos;

                    if (pos < 1 || pos > n) {
                        cout << "Invalid position.\n";
                    } else {
                        // shift left from pos to end
                        for (int i = pos - 1; i < n - 1; i++) {
                            arr[i] = arr[i + 1];
                        }
                        n--;
                        cout << "Deleted.\n";
                    }
                }
                break;
            }

            case 5: {
                if (n == 0) {
                    cout << "Array empty.\n";
                } else {
                    int key, found = -1;
                    cout << "Enter value to search: ";
                    cin >> key;

                    for (int i = 0; i < n; i++) {
                        if (arr[i] == key) { found = i; break; }
                    }

                    if (found == -1) cout << "Not found.\n";
                    else cout << "Found at position (1-based): " << (found + 1) << "\n";
                }
                break;
            }

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}
