#include <iostream>
#include <string>

using namespace std;

class Office {
private:
    string location;
    int seatingCapacity;
    string furniture[3];

public:
    // Parameterized Constructor
    Office(string loc = "", int capacity = 0, string furn1 = "", string furn2 = "", string furn3 = "") :
        location(loc), seatingCapacity(capacity) {
            furniture[0] = furn1;
            furniture[1] = furn2;
            furniture[2] = furn3;
    }

    // Function to display office information
    void displayInfo() {
        cout << "Location: " << location << endl;
        cout << "Seating Capacity: " << seatingCapacity << endl;
        cout << "Furniture: ";
        for (int i = 0; i < 3; ++i) {
            cout << furniture[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    // Creating objects with different numbers of arguments
    Office office1; // Zero arguments, defaults will be used
    Office office2("Downtown"); // One argument
    Office office3("Suburb", 50); // Two arguments
    Office office4("City Center", 100, "Desk", "Chair", "Computer"); // Three arguments

    // Display information for each office
    cout << "Office 1 Info:" << endl;
    office1.displayInfo();
    cout << endl;

    cout << "Office 2 Info:" << endl;
    office2.displayInfo();
    cout << endl;

    cout << "Office 3 Info:" << endl;
    office3.displayInfo();
    cout << endl;

    cout << "Office 4 Info:" << endl;
    office4.displayInfo();
    cout << endl;

    return 0;
}
