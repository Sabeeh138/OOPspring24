#include <iostream>
using namespace std;

class convert {
    protected:
    double val1;
    double val2;

    public:
    convert(double v1 = 0.0, double v2 = 0.0) : val1(v1), val2(v2) {}
    virtual void compute() = 0;

    double getVal1() const { return val1; }
    double getVal2() const { return val2; }
};

class LTOG: public convert {
    public:
    LTOG(double liters) : convert(liters) {}

    // Implementing compute() for liters to gallons conversion
    void compute() override {
        val2 = val1 * 0.264172; //
    }
};

class FTOC: public convert{
    public:
    FTOC(double fahr) : convert(fahr){}
    void compute() override {
        val2 = (val1 - 32) * 5.0 / 9.0; // Conversion formula from Fahrenheit to Celsius
    }
};

int main(){
    cout<<"programmer: Muhammad Sabeeh  ID: 23k-0002"<<endl;
    convert* c1 = new LTOG(4.0);
    convert* c2 = new FTOC(70.0);

    c1->compute();
    c2->compute();

    cout << "4 liters is equal to " << c1->getVal2() << " gallons." << endl;
    cout << "70 Fahrenheit is equal to " << c2->getVal2() << " Celsius." << endl;
    delete c1;
    delete c2;    
    return 0;
}
