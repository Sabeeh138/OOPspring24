#include <iostream>
#include <string>

using namespace std;

class Employee {
protected:
    int employeeID;
    string employeeName;
public:
    Employee(int id, string name) : employeeID(id), employeeName(name) {}

    virtual double calculatePay() const {
        return 0.0; // Default implementation, overridden in derived classes
    }

    virtual void displayDetails() const {
        cout << "Employee ID: " << employeeID << ", Employee Name: " << employeeName << endl;
    }
};

class FullTimeEmployee : public Employee {
private:
    double monthlySalary;
public:
    FullTimeEmployee(int id, string name, double salary)
        : Employee(id, name), monthlySalary(salary) {}

    double calculatePay() const override {
        return monthlySalary;
    }

    void displayDetails() const override {
        Employee::displayDetails();
        cout << "Monthly Salary: $" << monthlySalary << endl;
    }
};

class PartTimeEmployee : public Employee {
private:
    double hourlyWage;
    int hoursWorked;
public:
    PartTimeEmployee(int id, string name, double wage, int hours)
        : Employee(id, name), hourlyWage(wage), hoursWorked(hours) {}

    double calculatePay() const override {
        return hourlyWage * hoursWorked;
    }

    void displayDetails() const override {
        Employee::displayDetails();
        cout << "Hourly Wage: $" << hourlyWage << ", Hours Worked: " << hoursWorked << endl;
    }
};

int main() {
    cout<<"Name: Muhammad Sabeeh   ID: 23K-0002"<<endl;
    FullTimeEmployee fullTime(111, "John Doe", 4000.0);
    PartTimeEmployee partTime(222, "Jane Smith", 16.0, 50);

    cout << "Full-Time Employee Details:" << endl;
    fullTime.displayDetails();
    cout << "Pay: $" << fullTime.calculatePay() << endl << endl;

    cout << "Part-Time Employee Details:" << endl;
    partTime.displayDetails();
    cout << "Pay: $" << partTime.calculatePay() << endl << endl;

    Employee* empPtr;
    
    empPtr = &fullTime;
    cout << "Using base class pointer to calculate pay for full-time employee: $" << empPtr->calculatePay() << endl;

    empPtr = &partTime;
    cout << "Using base class pointer to calculate pay for part-time employee: $" << empPtr->calculatePay() << endl;

    return 0;
}
