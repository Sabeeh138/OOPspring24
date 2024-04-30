/*
    Name: Mohammad Yesaullah Sheikh
    Roll no: 23k-0019
*/
#include <iostream>
using namespace std;


class Perimeter
{
    float length, width;
    public:
    Perimeter(float l, float w) : length(l), width(w) {}
    friend class printClass;
};

class printClass
{
    public:
    void Print(Perimeter p) const
    {
        double temp;
        temp = p.length*2 + p.width*2;
        cout << "Perimeter is: " << temp << endl;
    }
};

int main(){
    cout<<"Name: Muhammad Sabeeh \n  ID: 23K-0002"<<endl;
    Perimeter p(2, 3);
    printClass print;

    print.Print(p);

    return 0;
}
