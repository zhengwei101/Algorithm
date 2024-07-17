#include "SortTestHelper.h"
#include "Student.h"
#include "SelectionSort.h"

int main() {
    int n = 10000;
    int* arr = SortTestHelper::generateRandomArray(n, 0, n);
    // selectionSort(arr, n);
    // SortTestHelper::printArray(arr, n);
    SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
    delete[] arr;

    float b[4] = {4.4, 1.1, 3.3, 2.2};
    selectionSort(b, 4);
    SortTestHelper::printArray(b, 4);

    std::string c[4] = {"D", "A", "B", "C"};
    selectionSort(c, 4);
    SortTestHelper::printArray(c, 4);

    Student d[4] = {{"D", 90}, {"A", 100}, {"C", 95}, {"B", 95}};
    selectionSort(d, 4);
    for (auto& i : d) {
        cout << i;
    }
       
    return 0;
}