/*
   Name: Muhammad Sabeeh
   Roll no: 23K-0002
   Purpose: Implement a program to manage a shop's inventory by adding items, retrieving the list, modifying prices, and displaying all items with their prices.
*/

#include <iostream>
#include <unistd.h> // For sleep() function on Unix-based systems
#include <windows.h> // For Sleep() function on Windows systems
using namespace std;

// I have supposed that the max number of items that could be stored are 100

int ptr = 0; // global variable pointing towards the next empty array element

class Shop {
    // Data members
    string item[100];
    float price[100];

    // Methods
    public:
        // Adds item name and its price
        void addItem(int c) {
            int i;
            for(i = 0; i < c; i++) {
                cout << "-----------------------------------------\n";
                cout << "--> Enter information for item " << i + 1 << ":" << endl;
                cin.ignore();
                cout << "    Item name: ";
                getline(cin, item[i]);
                cout << "    Item price: ";
                cin >> price[i]; // Fixed array index
                ptr++;
                cout << "-----------------------------------------\n";
            }
        }

        // Displays the list
        void retrieveList() {
            int i;
            if (ptr == 0) {
                cout << "-----------------------------------------\n";
                cout << "No items have yet been added to the list." << endl;
                cout << "-----------------------------------------\n";
            }
            else {
                for(i = 0; i < ptr; i++) {
                    cout << "-----------------------------------------\n";
                    cout << "Item " << i + 1 << ":" << endl;
                    cout << "    Item name: " << item[i] << endl;
                    cout << "-----------------------------------------\n";
                }
            }
        }

        // Modifies the price of an item
        void modifyPrice(float Price, int num) { // num is for the item number
            price[num - 1] = Price; // Fixed array index
        }

        // Displays all items along with their prices
        void display() {
            int i;
            for (i = 0; i < ptr; i++) {
                cout << "-----------------------------------------\n";
                cout << "--> Item no: " << i + 1 << ":" << endl;
                cout << "    Name: " << item[i] << endl;
                cout << "    Price: " << price[i] << endl;
                cout << "-----------------------------------------\n";
            }
        }
};

int main() {
    Shop s1;
    float price;
    int num;
    int choice;
    repeat:
    cout << "-----------------------------------------\n";
    cout << "--> Press '1' if you want to add an item and its price.\n"
         << "--> Press '2' if you want to retrieve the list of items.\n"
         << "--> Press '3' if you want to modify the price of items.\n"
         << "--> Press '4' if you want to display all the items along with their prices.\n"
         << "--> Press '0' to exit the program." << endl;
    cout << "-----------------------------------------\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cout << "-----------------------------------------\n";
    switch (choice) {
        case 0:
            cout << "***You have successfully exited the program***" << endl;
            exit(0);
            break;
        case 1:
            cout << "Enter the number of items you want to add: ";
            cin >> num;
            s1.addItem(num);
            cout << "***Item(s) added successfully***";
            sleep(5);
            system("cls");
            goto repeat;
            break;
        case 2:
            s1.retrieveList();
            sleep(5);
            system("cls");
            goto repeat;
            break;
        case 3:
            cout << "Enter the number of the item from the list: ";
            cin >> num;
            cout << "Enter new price: ";
            cin >> price;
            s1.modifyPrice(price, num);
            sleep(5);
            system("cls");
            goto repeat;
            break;
        case 4:
            s1.display();
            sleep(7);
            system("cls");
            goto repeat;
            break;
    }
    return 0;
}
