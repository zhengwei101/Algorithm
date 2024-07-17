#pragma once

#include <string>
#include <chrono>
#include <algorithm>

#include <cassert>
#include <ctime>

#include <iostream>
using std::cout;
using std::endl;

namespace SortTestHelper {
//生成有n个元素的随机数组，每个元素的随机范围为[rangeL, rangeR]
int* generateRandomArray(int n, int rangeL, int rangeR) {
    assert(rangeL <= rangeR);
    int* arr = new int[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
    return arr;
}

// 生成一个近乎有序的数组
// 首先生成一个含有[0...n-1]的完全有序数组, 之后随机交换swapTimes对数据
// swapTimes定义了数组的无序程度:
// swapTimes == 0 时, 数组完全有序
// swapTimes 越大, 数组越趋向于无序
int* generateNearlyOrderedArray(int n, int swapTimes) {

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
    srand(time(NULL));
    for (int i = 0; i < swapTimes; i++) {
        int posx = rand() % n;
        int posy = rand() % n;
        std::swap(arr[posx], arr[posy]);
    }
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
    //auto start_time = std::chrono::steady_clock::now();
    sort(arr, n);
    //auto end_time = std::chrono::steady_clock::now();
    clock_t endTime = clock();
    //std::chrono::duration<float> elapsed_seconds = end_time - start_time;
    assert(isSorted(arr, n));
    cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    //cout << sortName << " : " << elapsed_seconds.count() << "s" << endl;
}

int* copyIntArray(int a[], int n) {
    int* arr = new int[n];
    std::copy(a, a + n, arr);
    return arr;
}

} // namespace SortTestHelper
