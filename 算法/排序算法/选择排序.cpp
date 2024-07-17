#include "SortTestHelper.h"
#include "Student.h"

template <typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        // 寻找[i,n)区间里的最小值
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}


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
    for (auto& i : d)
        cout << i;
}