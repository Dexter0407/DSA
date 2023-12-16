#include <iostream>

void heap(int a[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        std::swap(a[i], a[largest]);
        heap(a, n, largest);
    }
}

void heapSort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heap(a, n, i);

    for (int i = n - 1; i >= 0; i--) {
        std::swap(a[0], a[i]);
        heap(a, i, 0);
    }
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    int a[n];
    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::cout << "Before sorting array elements are - \n";
    printArr(a, n);

    heapSort(a, n);

    std::cout << "After sorting array elements are - \n";
    printArr(a, n);

    return 0;
}