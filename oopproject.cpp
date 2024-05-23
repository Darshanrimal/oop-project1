
//Student management system

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    int id;
    string name;
    int age;
    string grade;
};

vector<Student> studentDatabase;

void addStudent() {
    Student newStudent;
    cout << "Enter student ID: ";
    cin >> newStudent.id;
    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, newStudent.name);
    cout << "Enter student age: ";
    cin >> newStudent.age;
    cout << "Enter student grade: ";
    cin >> newStudent.grade;
    studentDatabase.push_back(newStudent);
    cout << "Student added successfully!" << endl;
}

void displayStudents() {
    if (studentDatabase.empty()) {
        cout << "Student database is empty!" << endl;
        return;
    }
    cout << "Student Database:" << endl;
    for (const auto& student : studentDatabase) {
        cout << "ID: " << student.id << ", Name: " << student.name << ", Age: " << student.age << ", Grade: " << student.grade << endl;
    }
}

void searchStudent() {
    int searchID;
    cout << "Enter student ID to search: ";
    cin >> searchID;
    auto it = find_if(studentDatabase.begin(), studentDatabase.end(),
                      [searchID](const Student& student) { return student.id == searchID; });
    if (it != studentDatabase.end()) {
        cout << "Student found:" << endl;
        cout << "ID: " << it->id << ", Name: " << it->name << ", Age: " << it->age << ", Grade: " << it->grade << endl;
    } else {
        cout << "Student not found!" << endl;
    }
}

void deleteStudent() {
    int deleteID;
    cout << "Enter student ID to delete: ";
    cin >> deleteID;
    auto it = find_if(studentDatabase.begin(), studentDatabase.end(),
                      [deleteID](const Student& student) { return student.id == deleteID; });
    if (it != studentDatabase.end()) {
        studentDatabase.erase(it);
        cout << "Student deleted successfully!" << endl;
    } else {
        cout << "Student not found!" << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "\nStudent Management System Menu:\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                cout << "Exiting program. Goodbye!";
                break;
            default:
                cout << "Invalid choice. Please try again.";
        }
    } while(choice != 5);

    return 0;
}
