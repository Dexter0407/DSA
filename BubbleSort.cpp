#include <iostream>
#include <string>

using namespace std;

const int MAX_STUDENTS = 15;

struct Student {
    int rollNo;
    string name;
    float sgpa;
};

void bubbleSort(Student students[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (students[j].rollNo > students[j + 1].rollNo) {
                // Custom swap without using the algorithm library
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void insertionSort(Student students[], int size) {
    for (int i = 1; i < size; i++) {
        Student key = students[i];
        int j = i - 1;

        while (j >= 0 && students[j].name > key.name) {
            students[j + 1] = students[j];
            j = j - 1;
        }

        students[j + 1] = key;
    }
}

void printRollCall(const Student students[], int size) {
    cout << "Roll Call List:\n";
    for (int i = 0; i < size; i++) {
        cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].name << ", SGPA: " << students[i].sgpa << endl;
    }
}

void searchBySGPA(const Student students[], int size, float targetSGPA) {
    cout << "\nStudents with SGPA " << targetSGPA << ":\n";
    int found = 0;

    for (int i = 0; i < size; i++) {
        if (students[i].sgpa == targetSGPA) {
            cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].name << endl;
            found = 1;
        }
    }

    if (!found) {
        cout << "No students found with SGPA " << targetSGPA << endl;
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int numStudents;
    int ch;

    cout << "Enter the number of students (up to " << MAX_STUDENTS << "): ";
    cin >> numStudents;

    if (numStudents > MAX_STUDENTS) {
        cout << "Number of students exceeds the limit. Setting it to " << MAX_STUDENTS << ".\n";
        numStudents = MAX_STUDENTS;
    }

    for (int i = 0; i < numStudents; ++i) {
        cout << "\nEnter details for Student " << i + 1 << ":\n";
        cout << "Roll No: ";
        cin >> students[i].rollNo;
        cout << "Name: ";
        cin.ignore(); // Ignore the newline character in the buffer
        getline(cin, students[i].name);
        cout << "SGPA: ";
        cin >> students[i].sgpa;
    }

    do {
        cout << "\nOptions:\n";
        cout << "1. Display The Roll Call List\n";
        cout << "2. Bubble Sort\n";
        cout << "3. Insertion Sort (Arrange Alphabetically by Name)\n";
        cout << "4. Search Students by SGPA\n";
        cout << "5. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            // Displaying roll call list
            printRollCall(students, numStudents);
            break;
        case 2:
            // Sorting students by roll number using Bubble Sort
            bubbleSort(students, numStudents);
            cout << "Sorted List by Bubble Sort:\n";
            printRollCall(students, numStudents);
            break;
        case 3:
            // Sorting students alphabetically by name using Insertion Sort
            insertionSort(students, numStudents);
            cout << "Sorted List Alphabetically by Name (Insertion Sort):\n";
            printRollCall(students, numStudents);
            break;
        case 4:
            // Searching students by SGPA
            float targetSGPA;
            cout << "\nEnter SGPA to search: ";
            cin >> targetSGPA;
            searchBySGPA(students, numStudents, targetSGPA);
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (ch != 5);

return 0;
}