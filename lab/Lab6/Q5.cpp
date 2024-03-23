/*
    Name: Muhammad Sabeeh
    Roll no: 23k-0002
*/
#include <iostream>
using namespace std;

class Courses{
    string CourseCode, CourseName;
    int CreditHours;
    public:
    // constructor
    Courses(){}
    Courses(string code, string name, int credits) : CourseCode(code), CourseName(name), CreditHours(credits){}
    // getters
    string GetCode(){
        return CourseCode;
    }
    int GetCreditHours(){
        return CreditHours;
    }
    string GetName(){
        return CourseName;
    }
};

class Student{
    string StudentID, StudentName;
    Courses EnrolledCourses[8]; // assuming that a student can enroll in max 8 courses
    int num; // a variable to keep track of the number of enrolled courses
    public:
    // constructor
    Student(string id, string name){
        StudentID = id;
        StudentName = name;
        num = 0;
    }
    // function to add a course to enrolled courses array
    void enroll(Courses& course){
        if(num < 8){
            EnrolledCourses[num] = course;
            num++;
        }
        else{
            cout<<"The student can't enroll in any more courses."<<endl;
        }
    }
    // function to drop a course if it has already been added in the list of enrolled courses
    void drop(Courses& course){
        int i;
        for(i=0; i<num; i++){
            if(EnrolledCourses[i].GetCode() == course.GetCode()){
                for(int j=i; j<num-1; j++) {
                    EnrolledCourses[j] = EnrolledCourses[j+1];
                }
                num--;
                cout<<"Course dropped successfully."<<endl;
                break;
            }
        }
        if(i==num){
            cout<<"The student is not enrolled in the following course."<<endl;
        }
    }
    // function to calculate and return the total credit hours 
    int GetCreditHours(){
        int count = 0;
        int i;
        for(i=0; i<num; i++){
            count +=  EnrolledCourses[i].GetCreditHours();
        }
        return count;
    }
    void PrintEnrolledCourses(){
        int i; 
        for(i=0; i<num; i++){
            cout<<"Course Code: "<<EnrolledCourses[i].GetCode()<<endl;
            cout<<"Course Name: "<<EnrolledCourses[i].GetName()<<endl;
            cout<<"Credit Hours: "<<EnrolledCourses[i].GetCreditHours()<<endl;
        }
    }
};

int main(){
    Courses c1("CAL100", "Calculus", 3);
    Courses c2("OOP200", "OOP", 3);
    Courses c3("IRS300", "Islamiyat", 2);
    Courses c4("AP400", "Applied Physics", 3);
    Courses c5("OOPLAB200", "OOP Lab", 1);

    Student s1("23K-0002", "Muhammad Sabeeh");

    s1.enroll(c1);
    s1.enroll(c2);
    s1.enroll(c3);
    s1.enroll(c4);
    s1.enroll(c5);

    cout<<"--------------------------------------------"<<endl;
    s1.PrintEnrolledCourses();
    cout<<"--------------------------------------------"<<endl;
    cout<<"Total Credit Hours: "<<s1.GetCreditHours()<<endl;
    cout<<"--------------------------------------------"<<endl;

    Courses dropcourse("CAL100", "Calculus", 3);
    s1.drop(dropcourse);
    cout<<"--------------------------------------------"<<endl;
    s1.PrintEnrolledCourses();
    cout<<"--------------------------------------------"<<endl;
    cout<<"Total Credit Hours: "<<s1.GetCreditHours()<<endl;
    cout<<"--------------------------------------------"<<endl;
    return 0;
}
