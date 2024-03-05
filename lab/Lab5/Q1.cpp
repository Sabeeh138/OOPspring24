/*
    Name: Muhammad Sabeeh
    Roll no: 23K-0002
*/

#include <iostream> 
using namespace std;

class Square{
    private:
    float sidelength;
    float area;
    static float allareas;
    public:
    //default constructor
    Square() {
        sidelength = 0;
        area = 0;
    }
    //parameterized constructor
    Square(float sidelength){
        this->sidelength = sidelength;
        area = 0;
    }
    // getters and setters 
    void setlength(float sidelength){
        this->sidelength = sidelength;
    }
    void setArea(float area){
        this->area = area;
    }
    void setAllareas(float allareas){
        this->allareas = allareas;
    }
    float getlength(){
        return sidelength;
    }
    float getarea(){
        return area;
    }
    float getallareas(){
        return allareas;
    }
    // function to calculate the area
    void CalculateArea(){
        area = (sidelength)*(sidelength);
        allareas += area;
    }
};
// initialization of the static variable 
float Square::allareas = 0;

int main(){
    Square sq1(4); // object  creation using parameterized constructor
    sq1.CalculateArea(); // calling member function which calculates the area.
    cout<<"Area of the square = "<<sq1.getarea()<<endl;
    cout<<"The total area of all squares is = "<<sq1.getallareas()<<endl;

    // objects creation using default constructor
    Square sq2;

    float s;
    cout<<"\nEnter the side length for the square: ";
    cin>>s;
    sq2.setlength(s);
    sq2.CalculateArea();
    cout<<"Area of this square is equal to "<<sq2.getarea()<<endl;

    cout<<"\nThe total area of all the squares is = "<<sq2.getallareas()<<endl;
}
