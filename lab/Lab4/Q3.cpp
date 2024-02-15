/*
Muhammad Sabeeh
2/15/2023
*/
#include <iostream>
#include <string>

using namespace std;

class WeekDays {
private:
    string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int currentDay;

public:
    // Default Constructor
    WeekDays() {
        currentDay = 0; // Setting default day as Sunday
    }

    // Parameterized Constructor
    WeekDays(int day) {
        currentDay = day % 7; // Ensuring day is within range [0, 6]
    }

    // Function to get the current day
    string getCurrentDay() {
        return days[currentDay];
    }

    // Function to get the next day
    string getNextDay() {
        return days[(currentDay + 1) % 7];
    }

    // Function to get the previous day
    string getPreviousDay() {
        return days[(currentDay + 6) % 7];
    }

    // Function to get the Nth day from today
    string getNthDayFromToday(int n) {
        return days[(currentDay + n) % 7];
    }
};

int main() {
    int inputDay;
    cout << "Enter the number representing the day (0 for Sunday, 1 for Monday, etc.): ";
    cin >> inputDay;

    WeekDays week(inputDay);
    cout << "Current day: " << week.getCurrentDay() << endl;
    cout << "Next day: " << week.getNextDay() << endl;
    cout << "Previous day: " << week.getPreviousDay() << endl;

    int n;
    cout << "Enter the number of days to calculate from today: ";
    cin >> n;
    cout << n << " days from today: " << week.getNthDayFromToday(n) << endl;

    return 0;
}
