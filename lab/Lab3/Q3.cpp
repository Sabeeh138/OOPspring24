/*
	Name: Muhammad Sabeeh
	Roll no: 23k-0002
*/
#include <iostream>
#include <string>
using namespace std;

class Calendar {
private:
    string months[12][31]; // Array to store tasks for each day of each month
public:
    void addTask(int month, int day, const string& task) {
        if (month >= 1 && month <= 12 && day >= 1 && day <= 31) {
            months[month - 1][day - 1] = task;
            cout << "Task added successfully." << endl;
        } else {
            cout << "Invalid month or day." << endl;
        }
    }

    void removeTask(int month, int day) {
        if (month >= 1 && month <= 12 && day >= 1 && day <= 31) {
            months[month - 1][day - 1] = "";
            cout << "Task removed successfully." << endl;
        } else {
            cout << "Invalid month or day." << endl;
        }
    }

    void displayTasks() {
        for (int month = 0; month < 12; ++month) {
            switch (month + 1) {
                // Implementing switch cases for each month
            }
        }
    }
};

int main() {
    Calendar calendar;
    int choice, month, day;
    string task;
    
    while (true) {
        cout << "-----------------------------------------\n";
        cout << "1. Add a task\n";
        cout << "2. Remove a task\n";
        cout << "3. Display tasks\n";
        cout << "0. Exit\n";
        cout << "-----------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter month (1-12): ";
                cin >> month;
                cout << "Enter day (1-31): ";
                cin >> day;
                cin.ignore(); // Clear newline from buffer
                cout << "Enter task: ";
                getline(cin, task);
                calendar.addTask(month, day, task);
                break;
            case 2:
                cout << "Enter month (1-12): ";
                cin >> month;
                cout << "Enter day (1-31): ";
                cin >> day;
                calendar.removeTask(month, day);
                break;
            case 3:
                calendar.displayTasks();
                break;
            case 0:
                return 0; // Exiting the program
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
