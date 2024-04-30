/*
Name: Muhammad Sabeeh
ID:23K-0002
Purpose: code to show inheritance between cars and their types
*/

#include <iostream>
#include <string>

using namespace std;

//base class 
class Vehicle {
	protected:
    	string make;
    	string model;
    	int year;

	public:
    	//constructor to initialize member variables
    	Vehicle( string amake, string amodel, int ayear) : make(amake), model(amodel), year(ayear) {}

    	//function to display 
    	void display() const {
        	cout<<"Make: "<<make<<endl;
			cout<<"Model: "<<model<<endl;
			cout<<"Year: "<<year<<endl;
    	}
};

// Derived class 1
class Car : public Vehicle {
	protected:
    	int numDoors;
    	double fuelEfficiency;

	public:
    	//xonstructor to initialize base class and derived class member variables
    	Car(string amake, string amodel, int ayear, int anumDoors, double afuelEfficiency) 
		: Vehicle(amake, amodel, ayear), numDoors(anumDoors), fuelEfficiency(afuelEfficiency) {}

    	//function to display
    	void display() const {
        	Vehicle::display(); //initial function implementation called
        	cout<<"Number of Doors: "<<numDoors<<endl;
			cout<<"Fuel Efficiency: "<<fuelEfficiency<<"mpg"<<endl;
    }
};

// Derived class 2
class ElectricCar : public Car {
	protected:
    	double batteryLife;

	public:
    	
    	ElectricCar(string amake, string amodel, int ayear, int anumDoors, double afuelEfficiency, double abatteryLife)
        : Car(amake, amodel, ayear, anumDoors, afuelEfficiency), batteryLife(abatteryLife) {}

    	void display() const {
        	Car::display(); 
        	cout << ", Battery Life: "<<batteryLife<<" kWh"<<endl;
    }
};

int main() {
		cout<<"Muhammad Sabeeh\n23k-0002\n"<<endl;
    ElectricCar electricCar("TESLA", "Model-Y", 2020, 4, 95.5, 100);

    //display details of the electric car
    cout << "Details of Electric Car:" <<endl;
    electricCar.display();

    return 0;
}
