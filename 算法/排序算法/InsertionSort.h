#pragma once

template <typename T>
void insertionSort(T arr[], int n) {
    for (int i = 1; i < n; i++) {
        // 寻找元素arr[i]合适的插入位置
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
            std::swap(arr[j], arr[j - 1]);
        }
    }
}