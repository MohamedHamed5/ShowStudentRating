#include <iostream>
#include <string>
using namespace std;

// Struct to hold grade information: points, symbol, and rating
struct Grade {
    double points;
    string symbol;
    string rating;
};

// Function to get grade details based on the score
Grade getGradePoints(double score) {
    const double PercentageDegree[] = {96, 92, 88, 84, 80, 76, 72, 68, 64, 60, 55, 50, 0};
    const double points[] = {4.0, 3.7, 3.4, 3.2, 3, 2.8, 2.6, 2.4, 2.2, 2.0, 1.5, 1, 0.0};
    const string symbols[] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "D-", "F"};
    const string rating[] = {"Excellent", "Excellent", "Excellent", "Very Good", "Very Good", "Very Good", "Good", "Good", "Good", "Good",
                             "Pass", "Pass", "Pass", "Fail"};

    int size = sizeof(PercentageDegree) / sizeof(PercentageDegree[0]);

    for (int i = 0; i < size; i++) {
        if (score >= PercentageDegree[i]) {
            Grade grade = {points[i], symbols[i], rating[i]};
            return grade;
        }
    }
    Grade grade = {0.0, "F", "Fail"};
    return grade;
}

int main() {
    string names[] = {"Mohamed Ahmed Elsayed Hamed", "Mohamed Ahmed Hamed Elbyomi", "Ali Hassan"};
    int soz = sizeof(names) / sizeof(names[0]);

    string majors[] = {"Mathematics", "Science", "Mathematics"};

    string courses[][8] = {
        {"Mathematics 1", "Linear Algebra", "Electric Circuits", "English Language", "Computer Fundamentals", "Structured Programming", "Probabilities and Statistics"},
        {"Mathematics 0", "Mathematics 1", "Linear Algebra", "Electric Circuits", "English Language", "Computer Fundamentals", "Structured Programming", "Probabilities and Statistics"},
        {"Mathematics 1", "Linear Algebra", "Electric Circuits", "English Language", "Computer Fundamentals", "Structured Programming", "Probabilities and Statistics"}
    };

    double grades[][8] = {
        {85, 90, 99, 99, 99, 99, 99, 0},
        {88, 92, 85, 75, 80, 78, 90, 85},
        {95, 88, 76, 66, 70, 89, 80, 0}
    };

    int creditHours[][8] = {
        {3, 2, 3, 2, 2, 2, 2},
        {2, 3, 2, 3, 2, 2, 2, 2},
        {3, 2, 3, 2, 2, 2, 2}
    };

    string name, major;
    cout << "Enter your full name: ";
    getline(cin, name);

    // Search for the student in the system
    bool found = false;
    for (int i = 0; i < soz; i++) {
        if (names[i] == name) {
            found = true;
            cout << "\nWelcome, " << names[i] << ".\n";
            cout << "Your major: " << majors[i] << endl;
            cout << "Courses and their grades:\n";

            double totalPoints = 0;
            int numCourses = (majors[i] == "Mathematics") ? 7 : 8;
            int totalCreditHours = 0;

            for (int j = 0; j < numCourses; j++) {
                Grade grade = getGradePoints(grades[i][j]);
                cout << " -" << courses[i][j] << ": " << grades[i][j] << " points, Grade Points: " << grade.points
                     << ", Symbol: " << grade.symbol << ", Rating: " << grade.rating
                     << ", Credit Hours: " << creditHours[i][j] << endl;
                totalPoints += grade.points * creditHours[i][j];
                totalCreditHours += creditHours[i][j];
            }

            double gpa = totalPoints / totalCreditHours;
            cout << "Cumulative GPA: " << gpa << endl;
            break;
        }
    }

    if (!found) {
        cout << "Sorry, your information was not found in the system.\n";
        cout << "Welcome, let's sign in our system!\n";

        // Ask if the user wants to continue
        int choice;
        cout << "Do you want to continue registration? Enter 1 to continue, 0 to exit: ";
        cin >> choice;

        if (choice == 1) {
            cin.ignore();  // To clear the newline character left by the previous input
            cout << "Please enter your major (Mathematics  or Science): ";

            // Validate the major
            bool validMajor = false;
            while (!validMajor) {
                getline(cin, major);

                if (major == "Mathematics" || major == "Sceince") {
                    validMajor = true;
                } else {
                    cout << "Invalid major. Please enter either 'Mathematics' or 'Sceince'.\n";
                }
            }

            // Enter courses, grades, and credit hours
            int numCourses = (major == "Mathematics") ? 7 : 8;

            for (int j = 0; j < numCourses; j++) {
                bool validGrade = false;
                while (!validGrade) {
                    cout << "Enter grade for " << courses[0][j] << ": ";
                    cin >> grades[0][j];

                    if (grades[0][j] >= 0 && grades[0][j] <= 100) {
                        validGrade = true;
                    } else {
                        cout << "Invalid grade. Please enter a grade between 0 and 100.\n";
                    }
                }

                bool validCreditHour = false;
                while (!validCreditHour) {
                    cout << "Enter credit hours for " << courses[0][j] << ": ";
                    cin >> creditHours[0][j];

                    if (creditHours[0][j] > 0 && creditHours[0][j] <= 5) {
                        validCreditHour = true;
                    } else {
                        cout << "Invalid credit hours. Please enter a value between 1 and 5.\n";
                    }
                }
            }

            double totalPoints = 0;
            int totalCreditHours = 0;

            for (int j = 0; j < numCourses; j++) {
                Grade grade = getGradePoints(grades[0][j]);
                totalPoints += grade.points * creditHours[0][j];
                totalCreditHours += creditHours[0][j];
            }

            double gpa = totalPoints / totalCreditHours;
            cout << "Your GPA is: " << gpa << endl;
        } else {
            cout << "You chose not to continue the registration process.\n";
        }
    }

    return 0;
}



