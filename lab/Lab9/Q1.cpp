/*
Name: Muhammad Sabeeh
id:23k-0002
*/

#include <iostream>

using namespace std;

//global constant for the value of pi
const double PI = 3.14159265359;

class Shape {
	public:
    	//calculating area for a circle with formula pi*r*r
    	double Area(double radius) {
        	return PI * radius * radius;
    	}

    	//calculate area for rectangle with formula l*w
    	double Area(float length, float width) {
        	return length * width;
    	}

    	//calculating area for triangle with formula 0.5*b*h
    	double Area(float base, float height,int choice) {
        	return 0.5 * base * height;
    	}

    	//calculate perimeter for circle with formula of circumference
    	double Perimeter(double radius) {
        	return 2 * PI * radius;
    	}

    	//calculate perimeter for rectangle with formula of sum of all sides
    	double Perimeter(double length, double width) {
        	return 2 * (length + width);
    	}

    	//calculate perimeter for triangle with formula of sum of all sides
   		double Perimeter(double s1, double s2, double s3) {
        	return s1 + s2 + s3;
    	}
};

int main() {
	cout<<"Muhammad Sabeeh\n23k-0002"<<endl;
	//instance of the class
    Shape shape;

    // areas
    cout<<"Area of circle with radius 5: " << shape.Area(5)<<endl;
    cout<<"Area of rectangle with length 4 and width 6: " << shape.Area(4, 6)<<endl;
    //3rd argument is added only to differentiate between overloaded functions
    cout<<"Area of triangle with base 3 and height 8: " << shape.Area(3, 8,1)<<endl;
    cout<<endl;
    // perimeters
    cout<<"Perimeter of circle with radius 5: "<<shape.Perimeter(5)<<endl;
    cout<<"Perimeter of rectangle with length 4 and width 6: "<<shape.Perimeter(4, 6)<<endl;
    cout<<"Perimeter of triangle with sides 3, 4, and 5: "<<shape.Perimeter(3, 4, 5)<<endl;

    return 0;
}
