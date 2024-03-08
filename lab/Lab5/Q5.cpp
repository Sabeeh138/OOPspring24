/*
Name: Muhammad Sabeeh
id:23k-0002
*/

#include <iostream>
#include <string>

using namespace std;

class Engine {
private:
    string type;

public:
    Engine(const string& aType) : type(aType) {}

    void start() {
        cout<<"Engine of type " <<type<<" has started" << endl;
    }
};

class Wheel {
private:
    int size;

public:
    Wheel() {} //Default constructor 

    Wheel(int aSize) : size(aSize) {}

    void rotate() {
        cout << "Wheel of size " << size << " is rotating." << endl;
    }
};

class Headlight {
private:
    string company;

public:
    Headlight() {} 

    Headlight(const string& Brand) : company(Brand) {}

    void illuminate() {
        cout << "Headlight of brand " << company << " is working." << endl;
    }
};

class Steering {
private:
    string type;

public:
    Steering(const string& atype) : type(atype) {}

    void turn() {
        cout << "Steering of type " << type << " is turning" << endl;
    }
};

class Car {
private:
    Engine engine;
    Wheel* wheels;
    Headlight* headlights;
    Steering steering;

public:
    Car(const string& engineType, int wheelSize, const string& headlightBrand, const string& steeringType)
        : engine(engineType), steering(steeringType) {
        wheels = new Wheel[4];
        headlights = new Headlight[2];
        for (int i = 0; i < 4; ++i) {
            wheels[i] = Wheel(wheelSize);
        }
        for (int i = 0; i < 2; ++i) {
            headlights[i] = Headlight(headlightBrand);
        }
    }

    ~Car() {
        delete[] wheels;
        delete[] headlights;
    }

    void start() {
        engine.start();
    }

    void drive() {
        for (int i = 0; i < 4; ++i) {
            wheels[i].rotate();
        }
    }

    void turnOnLights() {
        for (int i = 0; i < 2; ++i) {
            headlights[i].illuminate();
        }
    }

    void turnSteering() {
        steering.turn();
    }
};

int main() {
    Car myCar("V12", 20, "pagani", "power");
    myCar.start();
    myCar.drive();
    myCar.turnOnLights();
    myCar.turnSteering();
    return 0;
}
