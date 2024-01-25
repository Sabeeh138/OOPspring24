#include <iostream>
#include <iomanip>

using namespace std;

// Function to calculate grade based on marks 
char calculateGrade(float average) {
    if (average >= 90) {
        return 'A';
    } else if (average >= 80) {
        return 'B';
    } else if (average >= 70) {
        return 'C';
    } else if (average >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

int main() {
    int numStudents;
   
    // Get the number of students from the user
    cout << "Enter the number of students: ";
    cin >> numStudents;

    for (int i = 1; i <= numStudents; ++i) {
        // Variables to store marks
        float mathMarks, englishMarks, scienceMarks;

        // Get marks for each subject
        cout << "Enter marks for student " << i << " (Math English Science): ";
        cin >> mathMarks >> englishMarks >> scienceMarks;

        // Calculate total and average marks
        float totalMarks = mathMarks + englishMarks + scienceMarks;
        float averageMarks = totalMarks / 3.0;

        // Calculate grade
        char grade = calculateGrade(averageMarks);

        // Display the results for each student
        cout << "\nStudent " << i << ":\n";
        cout << "Mathematics: " << mathMarks << "\n";
        cout << "English: " << englishMarks << "\n";
        cout << "Science: " << scienceMarks << "\n";
        cout << "Total Marks: " << totalMarks << "\n";
        cout << "Average Marks: " << std::fixed << std::setprecision(2) << averageMarks << "\n";
        cout << "Grade: " << grade << "\n\n";
    }

    return 0;
}
