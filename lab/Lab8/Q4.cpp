/*
    Name: Muhammad Sabeeh
    Roll no: 23k-0002
*/
#include <iostream>
using namespace std;

class Person{
    protected:
    string name;
    int age;
    public:
    Person(string n, int a){
        name = n;
        age = a;
    }
    void Display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<endl;
    }
};

class Student : public Person{
    protected:
    string stdID;
    string gradelevel;
    public:
    Student(string id, string grade, string n, int a) : Person(n, a){
        stdID = id;
        gradelevel = grade;
    }
    void displaystudent(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Student ID: "<<stdID<<endl;
        cout<<"Grade: "<<gradelevel<<endl;
    }
};

class Teacher : public Person{
    protected:
    string subject;
    int roomnum;
    public:
    Teacher(string sub, int num, string n, int a) : Person(n, a){
        subject = sub;
        roomnum = num;
    }
    void displayteacher(){
        cout<<"Subject: "<<subject<<endl;
        cout<<"Room Number: "<<roomnum<<endl;
    }
};

class GraduateStudent : public Teacher, public Student{
    public:
    GraduateStudent(string n, int a, string sub, int num, string ID, string grade) : Teacher(sub, num, n, a), Student(ID, grade, n, a){}
    void displayTA(){
        displaystudent();
        displayteacher();
    }
};

int main(){
    GraduateStudent student1("Sabeeh", 20, "OOP", 3, "23k-0002", "3.3");
    student1.displayTA();
}
