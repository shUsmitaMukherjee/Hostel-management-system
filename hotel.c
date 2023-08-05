
#include <iostream>
#include <string>
using namespace std;

// Structure to represent a student
struct Student {
    string name;
    int age;
    string roomNumber;
};

// Function to add a new student
void addStudent(Student students[], int& count) {
    if (count >= 100) {
        cout << "Hostel is full. Cannot add more students." << endl;
        return;
    }

    Student newStudent;
    cout << "Enter name: ";
    getline(cin >> ws, newStudent.name);
    cout << "Enter age: ";
    cin >> newStudent.age;
    cout << "Enter room number: ";
    getline(cin >> ws, newStudent.roomNumber);

    students[count] = newStudent;
    count++;

    cout << "Student added successfully." << endl;
}

// Function to remove a student
void removeStudent(Student students[], int& count) {
    if (count == 0) {
        cout << "No students in the hostel." << endl;
        return;
    }

    string name;
    cout << "Enter the name of the student to remove: ";
    getline(cin >> ws, name);

    int foundIndex = -1;
    for (int i = 0; i < count; i++) {
        if (students[i].name == name) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        // Shift elements to the left to remove the student
        for (int i = foundIndex; i < count - 1; i++) {
            students[i] = students[i + 1];
        }
        count--;

        cout << "Student removed successfully." << endl;
    } else {
        cout << "Student not found." << endl;
    }
}

// Function to display all students
void displayStudents(const Student students[], int count) {
    if (count == 0) {
        cout << "No students in the hostel." << endl;
        return;
    }

    cout << "Hostel students:" << endl;
    cout << "----------------------" << endl;
    for (int i = 0; i < count; i++) {
        cout << "Name: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "Room Number: " << students[i].roomNumber << endl;
        cout << "----------------------" << endl;
    }
}


int main() {
    Student students[100];  // Array to store students
    int count = 0;          // Counter for number of students


    int choice;
    while (true) {
        cout << "Hostel Management System" << endl;
        cout << "------------------------" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Remove Student" << endl;
        cout << "3. Display Students" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;


        switch (choice) {
            case 1:
                cin.ignore();  // Ignore the newline character left by previous cin
                addStudent(students, count);
                break;
            case 2:
                cin.ignore();  // Ignore the newline character left by previous cin
                removeStudent(students, count);
                break;
            case 3:
                displayStudents(students, count);
                break;
            case 4:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
    }
}

return 0;
}
Hostel-Management-System.cpp
Displaying Hostel-Management-System.cpp.