#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Base class Person
class Person {
protected:
    string name;
    int age;
    string ID;
    string contactInfo;

public:
    Person(string name, int age, string ID, string contactInfo)
        : name(name), age(age), ID(ID), contactInfo(contactInfo) {}

    virtual void displayDetails() const {
        cout << "Name: " << name << ", Age: " << age << ", ID: " << ID 
             << ", Contact: " << contactInfo << endl;
    }

    virtual double calculatePayment() const { return 0.0; }

    virtual ~Person() {}
};

// Derived class Student
class Student : public Person {
private:
    string enrollmentDate;
    string program;
    float GPA;

public:
    Student(string name, int age, string ID, string contactInfo, 
            string enrollmentDate, string program, float GPA)
        : Person(name, age, ID, contactInfo), enrollmentDate(enrollmentDate), 
          program(program), GPA(GPA) {}

    void displayDetails() const override {
        Person::displayDetails();
        cout << "Enrollment Date: " << enrollmentDate 
             << ", Program: " << program << ", GPA: " << GPA << endl;
    }

    double calculatePayment() const override { return 5000.0; }
};

// Derived class Professor
class Professor : public Person {
private:
    string department;
    string specialization;
    string hireDate;

public:
    Professor(string name, int age, string ID, string contactInfo, 
              string department, string specialization, string hireDate)
        : Person(name, age, ID, contactInfo), department(department), 
          specialization(specialization), hireDate(hireDate) {}

    void displayDetails() const override {
        Person::displayDetails();
        cout << "Department: " << department 
             << ", Specialization: " << specialization 
             << ", Hire Date: " << hireDate << endl;
    }

    double calculatePayment() const override { return 80000.0; }
};

// Class Course
class Course {
private:
    string code;
    string title;
    int credits;
    string description;

public:
    Course(string code, string title, int credits, string description)
        : code(code), title(title), credits(credits), description(description) {}

    void displayDetails() const {
        cout << "Course Code: " << code << ", Title: " << title 
             << ", Credits: " << credits << ", Description: " << description << endl;
    }
};

// Class Department
class Department {
private:
    string name;
    string location;
    double budget;

public:
    Department(string name, string location, double budget)
        : name(name), location(location), budget(budget) {}

    void displayDetails() const {
        cout << "Department: " << name << ", Location: " << location 
             << ", Budget: $" << budget << endl;
    }
};

// Class GradeBook
class GradeBook {
private:
    vector<pair<string, float>> grades;

public:
    void addGrade(string studentID, float grade) {
        grades.push_back({studentID, grade});
    }

    float calculateAverageGrade() {
        float sum = 0;
        for (const auto& entry : grades) {
            sum += entry.second;
        }
        return grades.empty() ? 0.0f : sum / grades.size();
    }
};

// Class EnrollmentManager
class EnrollmentManager {
private:
    vector<pair<string, string>> enrollments;

public:
    void enrollStudent(string studentID, string courseCode) {
        enrollments.push_back({studentID, courseCode});
    }

    int getEnrollmentCount() { return enrollments.size(); }
};

void testPolymorphism(Person* person) {
    person->displayDetails();
    cout << "Payment: $" << person->calculatePayment() << endl;
}

int main() {
    Student s1("Karan", 20, "S123", "karan@example.com", "2023-09-01", "Computer Science", 3.8);
    Professor p1("Ishatv", 25, "P456", "ishatv@example.com", "Engineering", "Data Science", "2015-06-20");

    testPolymorphism(&s1);
    testPolymorphism(&p1);

    return 0;
}