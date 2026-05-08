#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    int id;
    string name;
    int age;
    string department;
};

void addStudent(vector<Student>& students) {
    Student s;
    char again;

    do {
        cout << "\nAdd Student" << endl;

        cout << "ID: ";
        cin >> s.id;
        cin.ignore();

        cout << "Name: ";
        getline(cin, s.name);

        cout << "Age: ";
        cin >> s.age;
        cin.ignore();

        cout << "Department: ";
        getline(cin, s.department);

        students.push_back(s);

        cout << "Student added successfully." << endl;
        cout << "Add another student? (y/n): ";
        cin >> again;
        cin.ignore();

    } while (again == 'y' || again == 'Y');
}

void showStudents(const vector<Student>& students) {
    cout << "\nStudent List" << endl;

    if (students.empty()) {
        cout << "No students yet." << endl;
        return;
    }

    for (int i = 0; i < students.size(); i++) {
        cout << "\nStudent " << i + 1 << endl;
        cout << "ID: " << students[i].id << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "Department: " << students[i].department << endl;
    }
}

void searchStudent(const vector<Student>& students) {
    int searchId;
    bool found = false;

    cout << "\nEnter student ID: ";
    cin >> searchId;

    for (const auto& student : students) {
        if (student.id == searchId) {
            cout << "\nStudent found" << endl;
            cout << "ID: " << student.id << endl;
            cout << "Name: " << student.name << endl;
            cout << "Age: " << student.age << endl;
            cout << "Department: " << student.department << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found." << endl;
    }
}

void updateStudent(vector<Student>& students) {
    int searchId;
    bool found = false;

    cout << "\nEnter student ID to update: ";
    cin >> searchId;
    cin.ignore();

    for (auto& student : students) {
        if (student.id == searchId) {
            cout << "New name: ";
            getline(cin, student.name);

            cout << "New age: ";
            cin >> student.age;
            cin.ignore();

            cout << "New department: ";
            getline(cin, student.department);

            cout << "Student updated successfully." << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found." << endl;
    }
}

void deleteStudent(vector<Student>& students) {
    int searchId;
    bool found = false;

    cout << "\nEnter student ID to delete: ";
    cin >> searchId;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == searchId) {
            students.erase(students.begin() + i);
            cout << "Student deleted successfully." << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found." << endl;
    }
}

int main() {
    vector<Student> students;
    bool isRunning = true;

    while (isRunning) {
        int choice;

        cout << "\n==== Student Management System ====" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Show Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Update Student" << endl;
        cout << "5. Delete Student" << endl;
        cout << "6. Exit" << endl;
        cout << "Select: ";

        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                showStudents(students);
                break;
            case 3:
                searchStudent(students);
                break;
            case 4:
                updateStudent(students);
                break;
            case 5:
                deleteStudent(students);
                break;
            case 6:
                cout << "Goodbye!" << endl;
                isRunning = false;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
