/*
Name: Muhammad Sabeeh
id:23k-0002
*/
#include <iostream>

using namespace std;

class Number {
private:
    int value;

public:
    //parameterized constructor with initializer list
    Number(int val) : value(val) {}

    //overloading prefix decrement operator
    Number operator--() {
        value *= 4;
        return *this;
    }

    //postfix overload so int parameter is added
    Number operator--(int) {
        Number temp(value);
        value /=4;
        return temp;
    }

    // Method to display the value of the number
    void display() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    cout<<"Name: Muhammad Sabeeh \n ID: 23K-0002"<<endl;
    Number num(8);

    cout << "Original Value:" << endl;
    num.display();

    // Prefix decrement
    --num;
    cout << "Value after Prefix Decrement:" << endl;
    num.display();

    // Postfix decrement
    num--;
    cout << "Value after Postfix Decrement:" << endl;
    num.display();

    return 0;
}
