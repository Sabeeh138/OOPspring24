/*
   Name: Muhammad Sabeeh
   ID: 23k-0002
   Purpose: Define a program featuring a class for a board marker, including getter and setter methods along with additional functionality methods.
*/

#include <iostream>

using namespace std;

// The main class representing a board marker
class BoardMarker {
    // Private attributes accessible only within the class
    private:
        string brand;        // Brand of the marker
        string shade;        // Shade of ink
        bool refillable;     // Indicates if the marker is refillable
        bool ink_status;     // Indicates the ink status

    // Public getter and setter methods to access and modify private attributes
    public:
        // Setter methods
        void setBrand(string nbrand) {
            brand = nbrand;
        }
        
        void setShade(string nshade) {
            shade = nshade;
        }
    
        void setRefillable(bool refill) {
            refillable = refill;
        }
    
        void setInkStatus(bool nstatus) {
            ink_status = nstatus;
        }

        // Getter methods
        string getBrand() {
            return brand;
        }
        
        string getShade() {
            return shade;
        }
        
        bool getRefillable() {
            return refillable;
        }
        
        bool getInkStatus() {
            return ink_status;
        }
};

// Method to check if ink has run out and write with the marker
void write(BoardMarker marker) {
    if (marker.getInkStatus()) {
        cout << marker.getBrand() << " pen writing with a shade of " << marker.getShade() << endl;
        marker.setInkStatus(false);
        marker.setRefillable(true);
        return;
    }
    cout << "Depleted ink" << endl;
}

// Method to refill the ink if possible or required
void refill(BoardMarker marker) {
    if (marker.getRefillable()) {
        cout << "Refilling ink" << endl;
        marker.setRefillable(false);
        marker.setInkStatus(true);
        return;
    }
    cout << "Ink not depleted. Can't refill yet" << endl;
}

int main() {
    // Creating an instance of the BoardMarker class
    BoardMarker marker;
    
    // Setting values for the marker object using setter methods
    marker.setBrand("Casio");
    marker.setShade("Blue");

    // Testing functionality
    write(marker);
    write(marker);
    refill(marker);
    write(marker);

    return 0;
}
