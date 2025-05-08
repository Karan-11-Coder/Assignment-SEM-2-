#include <iostream>
#include <vector>  // For dynamic course list
using namespace std;

int num = 0;

class Student {
    string name;
    string roll_number;
    float CGPA;
    vector<string> courses;  // Use vector for dynamic course storage

public:
    void course();
    void grade();
    void display();
    void validate();
};

void Student::course() {
    cout << "Enter number of courses to add: ";
    cin >> num;
    cin.ignore();  // Prevent input skipping when using getline()

    courses.resize(num); // Resize vector to fit number of courses

    for (int i = 0; i < num; i++) {
        cout << "Enter name of course - " << i + 1 << ": ";
        getline(cin, courses[i]);
    }

    cout << "All courses have been successfully added" << endl;
}

void Student::grade() {
    cout << "Enter student roll number: ";
    cin.ignore();
    getline(cin, roll_number);
    cout << "Enter student CGPA: ";
    cin >> CGPA;
    cout << "CGPA has been successfully updated" << endl;
}

void Student::display() {
    cout << "Name: " << name << endl;
    cout << "Roll number: " << roll_number << endl;
    cout << "CGPA: " << CGPA << endl;

    if (!courses.empty()) {
        for (size_t i = 0; i < courses.size(); i++) {
            cout << "Course - " << i + 1 << ": " << courses[i] << endl;
        }
    } else {
        cout << "No course has been opted by student." << endl;
    }
}

void Student::validate() {
    // Implementation if needed
}

class StudentManagementSystem {
protected:
    string name;
    string roll_number;
    float CGPA;
    vector<string> courses;

public:
    // Default Constructor
    StudentManagementSystem() {
        name = "Unknown";
        roll_number = "XXXXXXX";
        CGPA = 0.0;
    }

    // Parameterized Constructor
    StudentManagementSystem(string n, string r_no, float GP) {
        name = n;
        roll_number = r_no;  // Fixed incorrect assignment
        CGPA = GP;

        cout << "Enter number of courses student has opted: ";
        cin >> num;
        cin.ignore();
        courses.resize(num);

        for (int i = 0; i < num; i++) {
            cout << "Enter name of course - " << i + 1 << ": ";
            getline(cin, courses[i]);
        }
    }

    void display_record();
};

 void StudentManagementSystem::display_record () {
    
 }

int main() {
    int num2;
    cout << "Enter number of students in class: ";
    cin >> num2;

    StudentManagementSystem S1_A[] = {
        {"Ankit", "24A1001", 6.5},
        {"Avesh", "24A2002", 7.6}
    };

    return 0;
}