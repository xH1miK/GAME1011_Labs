#include <iostream>

template<typename T>
void Sort(T A[], int n) {
    for (int i = 1; i < n; i++) {
        T key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
}

template<typename T>
void PrintArray(T A[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Example usage with integers
    int arrInt[] = { 10, 7, 8, 9, 1, 5 };
    int nInt = sizeof(arrInt) / sizeof(arrInt[0]);
    Sort(arrInt, nInt);
    std::cout << "Sorted array (int): ";
    PrintArray(arrInt, nInt);

    // Example usage with double
    double arrDouble[] = { 4.5, 2.3, 3.7, 1.5, 5.9 };
    int nDouble = sizeof(arrDouble) / sizeof(arrDouble[0]);
    Sort(arrDouble, nDouble);
    std::cout << "Sorted array (double): ";
    PrintArray(arrDouble, nDouble);

    return 0;
}
