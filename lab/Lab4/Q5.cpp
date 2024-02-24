/*
Name: Muhammad Sabeeh
ID: 23K-0002
*/

#include <iostream>
#include <string>

using namespace std;

class Office {
private:
    string location;
    int seatingCapacity;
    string* furniture; // Pointer to array "furniture" that will store all the furniture in the office

public:
    // Parameterized constructor with default values and dynamic memory allocation for the "furniture" array
    Office(string loc = "", int capacity = 0, int furnitureNum = 3) :
        location(loc), seatingCapacity(capacity) {
        furniture = new string[furnitureNum];
    }
    
    // Destructor to deallocate memory for the "furniture" array
    ~Office() {
        delete[] furniture;
    }
    
    // Function to set furniture in the array at the next available location
    void setFurniture(int index, const string& item) {
        furniture[index] = item;
    }
    
    // Function to display office information
    void displayInfo() {
        cout << "Location: " << location << endl;
        cout << "Seating Capacity: " << seatingCapacity << endl;
        cout << "Furniture: ";
        for (int i = 0; i < 3; i++) {
            cout << furniture[i];
            if (i < 2)
                cout << ", ";
        }
        cout << endl;
    }
};

int main() {
    // Initializing a pointer of type "Office" to store the object of the class and giving it initial values for some data members
    Office* officePtr = new Office("Clifton", 100, 3);
    
    // Giving values to the furniture array
    officePtr->setFurniture(0, "table");
    officePtr->setFurniture(1, "chair");
    officePtr->setFurniture(2, "PC"); 

    // Displaying the office information
    cout << "Office Info:" << endl;
    officePtr->displayInfo();
    cout << endl;
    
    // Clearing the dynamically allocated memory
    delete officePtr;
    
    return 0;
}
