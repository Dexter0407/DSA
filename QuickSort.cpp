#include<iostream>
using namespace std;
struct Student {
  int rollNo;
  string name;
  float sgpa;
};

// Quick sort partition function to sort students by SGPA in descending order
int partition(Student arr[], int low, int high) {
  float pivot = arr[high].sgpa;
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (arr[j].sgpa >= pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return i + 1;
}

// Quick sort function to sort students by SGPA
void quickSort(Student arr[], int low, int high) {
  if (low < high) {
    int q = partition(arr, low, high);
    quickSort(arr, low, q - 1);
    quickSort(arr, q + 1, high);
  }
}

// Print the first ten toppers
void printTopThreeToppers(Student arr[], int n) {
  quickSort(arr, 0, n - 1);
  cout << "First ten toppers:" << endl;
  for (int i = 0; i < 3; i++) {
    cout << arr[i].name << " (" << arr[i].sgpa << ")" << endl;
  }
}

int binarySearch(Student arr[], int low, int high, string name) {
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid].name == name) {
      return mid;
    } else if (arr[mid].name < name) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1; 
}

void searchStudentByName(Student arr[], int n, string name) {
  int index = binarySearch(arr, 0, n - 1, name);
  if (index == -1) {
    cout << "Student " << name << " not found in the database." << endl;
  } else {
    cout << "Student " << name << " found at index " << index << endl;
    cout << "Roll number: " << arr[index].rollNo << endl;
    cout << "SGPA: " << arr[index].sgpa << endl;
  }
}

const int MAX_STUDENTS = 15; 

int main() {
  Student students[MAX_STUDENTS]; 
  int numStudents; 

  
  do {
    cout << "Enter the number of students (1-15): ";
    cin >> numStudents;
  } while (numStudents < 1 || numStudents > MAX_STUDENTS);

  
  for (int i = 0; i < numStudents; ++i) {
    cout << "Enter student " << i + 1 << " details:" << endl;
    cout << "- Roll number: ";
    cin >> students[i].rollNo;
    cout << "- Name: ";
    cin >> students[i].name;
    cout << "- SGPA: ";
    cin >> students[i].sgpa;
  }
  int choice;
  bool exit = false;
  while (!exit) {
    cout << std::endl << "SEIT Student Database" << endl;
    cout << "1. Find Top 3 Toppers" << endl;
    cout << "2. Search Student by Name" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
      printTopThreeToppers(students, numStudents); // Use your quick sort function
    } else if (choice == 2) {
      string name;
      cout << "Enter student name to search: ";
      cin >> name;
      searchStudentByName(students, numStudents, name); // Use your binary search function
    } else if (choice == 3) {
      exit = true;
    } else {
      cout << "Invalid choice. Please try again." << endl;
    }
  }

  cout << "Exiting..." << endl;

  return 0;
}
  
























