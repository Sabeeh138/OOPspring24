#include <iostream>
using namespace std;
class Shape{
private:
    float area;
    public:
        Shape(): area(25){}
    
    Shape operator+ (Shape &obj){
        Shape obj2;
        obj2.area = area + obj2.area;
        return obj2;
    }
    void print()
    {
        cout<<"the area is : "<<area<<endl;
    }
};

int main(){
    cout<<"programmer: Muhammad Sabeeh    ID: 23K-0002"<<endl;
    Shape sh1, sh2;
    cout << "area of shape 1 is:";
    sh1.print();
    cout << "area of shape 2 is:";
    sh2.print();

    Shape sh3;
    sh3= sh1 + sh2;
    cout<<"area of shape 3 is:"; 
    sh3.print();
    return 0;
}
