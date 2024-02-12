/*
name: Muhammad Abbas
ID: 23k-0068
purpose: a product management system with a user interface
*/

#include<iostream>
#include<unistd.h>// Header added for sleep() function to pause program

using namespace std;

// Global variable to hold the number of items in the main database array
int position = 0;

// Structure template for each product
struct product {
    int productid; // Product ID
    string name; // Product name
    float price; // Product price
    int quantity; // Product quantity
};

// Global array of structures as it has to be used outside the main function
product products[100];

// Function to add new product records to the array
void addProduct(product products[], int &position) {
    cout << "Add the details of the product you want to add to the database" << endl;
    cout << "Enter the product ID: ";
    cin >> products[position].productid;
    cout << "Enter the product name: ";
    cin.ignore(); // Clearing the input buffer
    getline(cin, products[position].name);
    cout << "Enter the product price: ";
    cin >> products[position].price;
    cout << "Enter the product quantity: ";
    cin >> products[position].quantity;
    cout << "\nProduct added successfully!" << endl;
    position++; // Incrementing the global variable telling the number of items in the array so next time the next location in the array is used to store the next data
}

// Function to find a product from the array
void findProduct(product products[], int productid) {
    for (int i = 0; i < position; i++) {
        if (products[i].productid == productid) {
            cout << "Product found" << endl;
            cout << "Product ID: " << products[i].productid << endl;
            cout << "Product name: " << products[i].name << endl;
            cout << "Product price: " << products[i].price << endl;
            cout << "Product quantity: " << products[i].quantity << endl;
            return;
        }
    }
    cout << "No such product found" << endl;
}

// Function to update existing record
void updateRecord(product products[], int productid) {
    for (int i = 0; i < position; i++) {
        if (products[i].productid == productid) {
            cout << "Add new product name: ";
            cin.ignore(); // Clearing buffer
            getline(cin, products[i].name);
            cout << "Add new product price: ";
            cin >> products[i].price;
            cout << "Add new product quantity: ";
            cin >> products[i].quantity;
            cout << "Record updated successfully!" << endl;
            return;
        }
    }
    cout << "No such product found" << endl;
}


int main() {
    int choice;
    // Label used to bring back program execution here when required
    again:
    cout << "\t\t\t\t   Welcome to the Product Management System";
    cout << "\n\n\t\t\t\t********Choose from the following options:*******\n\n" << endl;
    cout << "\t\t\t\t|-----------------------------------------------|" << endl;
    cout << "\t\t\t\t|-----------------------------------------------|" << endl;
    cout << "\t\t\t\t|    1) Add a product to the database           |" << endl;
    cout << "\t\t\t\t|    2) Find a product from the database        |" << endl;
    cout << "\t\t\t\t|    3) Update an existing record               |" << endl;
    cout << "\t\t\t\t|    4) Exit                                    |" << endl;
    cout << "\t\t\t\t|-----------------------------------------------|" << endl;
    cout << "\t\t\t\t|-----------------------------------------------|" << endl;
    cout << "Enter your choice:" << endl;
    cin >> choice;
    
    // Calling the respective functions based on user choice
    switch (choice) {
        case 1:
            addProduct(products, position);
            break;
        
        case 2:
            int productid;
            cout << "Enter the ID of the product you want to find: ";
            cin >> productid;
            findProduct(products, productid);
            break;
        
        case 3:
            int productid2;
            cout << "Enter the ID of the product you want to update: ";
            cin >> productid2;
            updateRecord(products, productid2);
            break;
        
        case 4:
            cout << "Thank you for using the product management system :)" << endl;
            exit(0); // Function to exit the program
            break;
        
        default:
            cout << "Wrong input. Reloading program. Please choose again." << endl;
            sleep(2); // Function to pause the program for required seconds
            break;
    }
    // Goto statement will take program execution to where the mentioned label is
    goto again;
}
