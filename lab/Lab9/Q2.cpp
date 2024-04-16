#include <iostream>
#include <cmath>

using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void displayProperties() const = 0;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return M_PI * radius * radius;
    }

    double perimeter() const override {
        return 2 * M_PI * radius;
    }

    void displayProperties() const override {
        cout << "Circle Properties:" << endl;
        cout << "Radius: " << radius << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};

class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() const override {
        return length * width;
    }

    double perimeter() const override {
        return 2 * (length + width);
    }

    void displayProperties() const override {
        cout << "Rectangle Properties:" << endl;
        cout << "Length: " << length << ", Width: " << width << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};

class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {}

    void displayProperties() const override {
        cout << "Square Properties:" << endl;
        cout << "Side Length: " << Rectangle::area() << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};

class Triangle : public Shape {
private:
    double side1, side2, side3;
public:
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}

    double area() const override {
        double s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    double perimeter() const override {
        return side1 + side2 + side3;
    }

    void displayProperties() const override {
        cout << "Triangle Properties:" << endl;
        cout << "Side 1: " << side1 << ", Side 2: " << side2 << ", Side 3: " << side3 << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double side) : Triangle(side, side, side) {}

    void displayProperties() const override {
        cout << "Equilateral Triangle Properties:" << endl;
        cout << "Side Length: " << Triangle::area() << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};

int main() {
    cout <<"Name: Muhammad Sabeeh   ID:23K-0002"<<endl;
    Shape* shapes[5];
    shapes[0] = new Circle(5);
    shapes[1] = new Rectangle(4, 6);
    shapes[2] = new Square(5);
    shapes[3] = new Triangle(3, 4, 5);
    shapes[4] = new EquilateralTriangle(6);

    for (int i = 0; i < 5; ++i) {
        shapes[i]->displayProperties();
        cout << endl;
        delete shapes[i]; // Deallocate memory
    }

    return 0;
}
