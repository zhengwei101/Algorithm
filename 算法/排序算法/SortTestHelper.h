#pragma once

#include <string>
#include <chrono>
#include <cassert>
#include <ctime>

#include <iostream>
using std::cout;
using std::endl;

namespace SortTestHelper {
//生居有n个元素的随机数组，每个元素的随机范围为[rangeL, rangeR]
int* generateRandomArray(int n, int rangeL, int rangeR) {
    assert(rangeL <= rangeR);
    int* arr = new int[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
    return arr;
}

template <typename T>
void printArray(T arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

template <typename T>
bool isSorted(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

template <typename T>
void testSort(std::string sortName, void (*sort)(T[], int), T arr[], int n) {
    clock_t startTime = clock();
    auto start_time = std::chrono::steady_clock::now();
    sort(arr, n);
    auto end_time = std::chrono::steady_clock::now();
    clock_t endTime = clock();
    clock_t duration = endTime - startTime;
    std::chrono::duration<float> elapsed_seconds = end_time - start_time;
    assert(isSorted(arr, n));
    cout << sortName << " : " << double(duration) / CLOCKS_PER_SEC << "s" << endl;
    cout << sortName << " : " << elapsed_seconds.count() << "s" << endl;
}
} // namespace SortTestHelper
