#include <iostream>
#include <cstring>
using namespace std;

struct Friend {
    char name[30];
    char mobile[15];
};

int main() {
    Friend phoneBook[100];
    int n = 0, choice;

    do {
        cout << "\n\n===== PHONE BOOK =====";
        cout << "\n1. Insert Friend";
        cout << "\n2. Search Friend";
        cout << "\n3. Delete Friend"; 
        cout << "\n4. Sort Phone Book";
        cout << "\n5. Display Phone Book";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        // INSERT
        if (choice == 1) {
            char name[30], mobile[15];

            cout << "\nEnter name: ";
            cin >> name;

            // Sentinel Search to check duplicate
            int pos = -1;

            if (n > 0) {
                Friend last = phoneBook[n - 1];

                strcpy(phoneBook[n - 1].name, name);

                int i = 0;
                while (strcmp(phoneBook[i].name, name) != 0)
                    i++;

                phoneBook[n - 1] = last;

                if (i < n - 1 || strcmp(last.name, name) == 0)
                    pos = i;
            }

            if (pos != -1) {
                cout << "Friend already exists!";
            }
            else {
                cout << "Enter mobile number: ";
                cin >> mobile;

                strcpy(phoneBook[n].name, name);
                strcpy(phoneBook[n].mobile, mobile);
                n++;

                // Sort alphabetically
                for (int i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (strcmp(phoneBook[j].name,
                                   phoneBook[j + 1].name) > 0) {
                            swap(phoneBook[j], phoneBook[j + 1]);
                        }
                    }
                }

                cout << "Friend inserted successfully!";
            }
        }

        // SEARCH - SENTINEL SEARCH
        else if (choice == 2) {
            char name[30];

            cout << "\nEnter name to search: ";
            cin >> name;

            int pos = -1;

            if (n > 0) {
                Friend last = phoneBook[n - 1];

                // Put key at last position as sentinel
                strcpy(phoneBook[n - 1].name, name);

                int i = 0;

                while (strcmp(phoneBook[i].name, name) != 0)
                    i++;

                // Restore last element
                phoneBook[n - 1] = last;

                if (i < n - 1 || strcmp(last.name, name) == 0)
                    pos = i;
            }

            if (pos != -1) {
                cout << "\nFriend found!";
                cout << "\nName   : " << phoneBook[pos].name;
                cout << "\nMobile : " << phoneBook[pos].mobile;
                cout << "\nIndex  : " << pos;
            }
            else {
                cout << "\nFriend not found!";
            }
        }

        // DELETE
        else if (choice == 3) {
            char name[30];

            cout << "\nEnter name to delete: ";
            cin >> name;

            int pos = -1;

            // Sentinel Search
            if (n > 0) {
                Friend last = phoneBook[n - 1];

                strcpy(phoneBook[n - 1].name, name);

                int i = 0;

                while (strcmp(phoneBook[i].name, name) != 0)
                    i++;

                phoneBook[n - 1] = last;

                if (i < n - 1 || strcmp(last.name, name) == 0)
                    pos = i;
            }

            if (pos == -1) {
                cout << "Friend not found!";
            }
            else {
                // Shift elements left
                for (int i = pos; i < n - 1; i++)
                    phoneBook[i] = phoneBook[i + 1];

                n--;

                cout << "Friend deleted successfully!";
            }
        }

        // SORT
        else if (choice == 4) {
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                    if (strcmp(phoneBook[j].name,
                               phoneBook[j + 1].name) > 0) {
                        swap(phoneBook[j], phoneBook[j + 1]);
                    }
                }
            }

            cout << "\nPhone book sorted successfully!";
        }

        // DISPLAY
        else if (choice == 5) {
            if (n == 0) {
                cout << "\nPhone book is empty!";
            }
            else {
                cout << "\n\n===== PHONE BOOK =====\n";

                for (int i = 0; i < n; i++) {
                    cout << "Index: " << i
                         << " | Name: " << phoneBook[i].name
                         << " | Mobile: " << phoneBook[i].mobile
                         << endl;
                }
            }
        }

        // EXIT
        else if (choice == 6) {
            cout << "\nProgram ended.";
        }

        else {
            cout << "\nInvalid choice!";
        }

    } while (choice != 6);

    return 0;
}