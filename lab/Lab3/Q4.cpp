/*
   Name: Muhammad Sabeeh
   ID: 23k-0002
   Purpose: Implementing a class template for a smartphone with various functionalities.
*/

#include<iostream>
using namespace std;

class Smartphone {
    // Private data attributes of the phone
    private:
        string brand;
        string model;
        int display_res;
        int ram;
        int rom;
        int storage;
        
    public:
        // Setter methods
        void setBrand(string abrand) {
            brand = abrand;
        }
        void setModel(string amodel) {
            model = amodel;
        }
        void setResolution(int ares) {
            display_res = ares;
        }
        void setRAM(int aram) {
            ram = aram;
        }
        void setROM(int arom) {
            rom = arom;
        }
        void setStorage(int astorage) {
            storage = astorage;
        }
        
        // Getter methods
        string getBrand() {
            return brand;
        }
        string getModel() {
            return model;
        }
        int getResolution() {
            return display_res;
        }
        int getRAM() {
            return ram;
        }
        int getROM() {
            return rom;
        }
        int getStorage() {
            return storage;
        }
        
        // Additional functionality methods
        void makeCall(string contactName) {
            cout << "Dialing call to " << contactName << endl;
        }
        
        void sendMessage(string recipient) {
            cout << "Sending message to " << recipient << endl;
        }
        
        void connectToWiFi(string networkName) {
            cout << "Connecting to WiFi network " << networkName << endl;
        }
        
        void browseInternet(string webpage) {
            cout << "Browsing the internet for the webpage " << webpage << endl;
        }
};

int main() {
    // Instance 1 of the class
    Smartphone iphone;
    iphone.setBrand("iPhone");
    iphone.setModel("13 Pro");
    iphone.setResolution(1024);
    iphone.setRAM(8);
    iphone.setROM(1000);
    iphone.setStorage(10000);
    cout << "Phone information:\n";
    cout << "Brand: " << iphone.getBrand() << endl;
    cout << "Model: " << iphone.getModel() << endl;
    cout << "Screen resolution: " << iphone.getResolution() << endl;
    cout << "RAM: " << iphone.getRAM() << "GB" << endl;
    cout << "ROM: " << iphone.getROM() << "GB" << endl;
    cout << "Storage: " << iphone.getStorage() << "GB" << endl;
    iphone.makeCall("Muhammad");
    iphone.sendMessage("John");
    iphone.connectToWiFi("WITRIBE");
    iphone.browseInternet("YouTube");
    
    // Instance 2 of the class
    Smartphone redmi;
    redmi.setBrand("Redmi");
    redmi.setModel("13C");
    redmi.setResolution(2048);
    redmi.setRAM(8);
    redmi.setROM(1200);
    redmi.setStorage(12000);
    cout << "\nPhone information:\n";
    cout << "Brand: " << redmi.getBrand() << endl;
    cout << "Model: " << redmi.getModel() << endl;
    cout << "Screen resolution: " << redmi.getResolution() << endl;
    cout << "RAM: " << redmi.getRAM() << "GB" << endl;
    cout << "ROM: " << redmi.getROM() << "GB" << endl;
    cout << "Storage: " << redmi.getStorage() << "GB" << endl;
    redmi.makeCall("Ahmed");
    redmi.sendMessage("Tom");
    redmi.connectToWiFi("PTCL");
    redmi.browseInternet("Facebook");

    return 0;
}
